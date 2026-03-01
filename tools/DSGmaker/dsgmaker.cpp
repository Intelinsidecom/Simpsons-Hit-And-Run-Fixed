//DSGmaker a tool to traverse the the inventory of a Pure3d file and creates 
//DSGchucks and bundles mesh,phys,BV,instance chunk together. Supports multiple objects in a file.

#pragma warning(disable:4786)

#include <iostream>
#include <cstring>
#include <iomanip>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include "..\ArtChecker\artobject.h"
#include "..\ArtChecker\artlimits.h"
#include "..\ArtChecker\badlist.hpp"
//#include "..\ArtChecker\outputbuffer.hpp"


#include <toollib.hpp>
#include <tlCollisionObjectChunk.hpp>
#include <tlPhysicsObjectChunk.hpp>
#include <tlMeshChunk.hpp>
#include "..\..\game\code\constants\srrchunks.h"
#include "DSGList.hpp"
using namespace std;

//function that strips all the extra crap(prefixes and appended junk)
//and returns actual object name  in output pointer.

unsigned int rootname(const char* input,char* output);

static void StripTrailingDigits(const char* input, char* output)
{
    strcpy(output, input);
    int len = (int)strlen(output);
    while (len > 0)
    {
        char c = output[len - 1];
        if (c >= '0' && c <= '9')
        {
            output[len - 1] = '\0';
            len--;
            continue;
        }
        break;
    }
}


int main(int argc, char* argv[])
{
    
    //char* arguements [4];
    char* filename;
    char querybuffer [1000];
    bool badart = false;
    bool showall= false;
    
    struct ObjectMetadata {
        std::string ClassType;
        int physpropid;
        std::string Sound;
    };
    std::map<std::string, ObjectMetadata> metadataMap;

    DSGList* p_dsglist =new DSGList();
    bool mbIgnoreMissingInstanceChunk = false;

    tlDataChunk::RegisterDefaultChunks();

    //processes arguements
    
    //no options 
    if (argc ==1)
    {
        cout<<"Usage:Dsgmaker filename \n";
        exit (1);
    }
        
    filename= argv[1];

    if ( argc ==3)
    {
        if (strcmp( argv[2],"-nI") == 0)
        {
            mbIgnoreMissingInstanceChunk = true;
            //printf("Ignoring Missing Chunks!\n");
        }
        else
        {
            printf("Error: unknown arguement %s \n",argv[2]);
        }
    }

/*  
    for (i=2;i<argc;i++)
    {
        arguements[i]=argv[i];

        // user set strict
        if (strcmp(arguements[i],"strict")== 0)
        {
            strict =true;
            debugstring("strict option set");
            break;
        }
                        
        //user set add
        
        else if (strcmp (arguements[i],"add")==0)
        {
            add=true;
            debugstring("add option set");
            break;
        }

        else if (strcmp (arguements[i],"all")==0)
        {
            showall =true;
            break;
        }
        //illegal option
        else 
        {
            cout <<arguements[i] <<" is an illegal option \n";
            exit (1);
        }
            
#ifdef DEBUG
        cout<< i ;
        cout<< arguements [i] << "\n";
#endif
    
    } //end for

   */

     //read in the pure3d file name

    tlFile input(new tlFileByteStream(filename,omREAD), tlFile::FROMFILE);
    if(!input.IsOpen()) 
    {
        printf("Could not open %s\n", filename);
        exit(-1);
    }

    cout<<"Processing Filename:"<<filename<<endl;

    //desend into the file and look at each object until no more objects left
        
    // make a tlDataChunk from the file
    // this is the wrapper chunk for the input
    tlDataChunk* inchunk = new tlDataChunk(&input);
    // we don't need the tlFile anymore
    // this cleans up the tlFile object including the
    // tlFileByteStream
    input.Close();


    // Load Local Metadata if it exists
    // First try to get the executable directory
    char exePath[MAX_PATH];
    GetModuleFileName(NULL, exePath, MAX_PATH);
    
    // Manually remove the executable name to get directory
    char* lastSlash = strrchr(exePath, '\\');
    if (lastSlash) {
        *lastSlash = '\0';
    }
    
    // Try to load from executable directory first
    std::string metadataPath = std::string(exePath) + "\\dsg_metadata.csv";
    std::ifstream metadataFile(metadataPath.c_str());
    
    // If not found in exe directory, try current directory
    if (!metadataFile.is_open()) {
        metadataFile.open("dsg_metadata.csv");
        if (metadataFile.is_open()) {
            cout << "Using dsg_metadata.csv from current directory" << endl;
        }
    } else {
        cout << "Using dsg_metadata.csv from executable directory" << endl;
    }
    
    if (metadataFile.is_open()) {
        std::string line;
        while (std::getline(metadataFile, line)) {
            // Very simple CSV parser: name,ClassType,physpropid,Sound
            size_t pos = 0;
            std::vector<std::string> tokens;
            while ((pos = line.find(',')) != std::string::npos) {
                tokens.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            tokens.push_back(line);
            if (tokens.size() >= 4) {
                ObjectMetadata meta;
                meta.ClassType = tokens[1];
                meta.physpropid = atoi(tokens[2].c_str());
                meta.Sound = tokens[3];
                metadataMap[tokens[0]] = meta;
            }
        }
        cout << "Loaded " << metadataMap.size() << " entries from dsg_metadata.csv" << endl;
    } else {
        cout << "dsg_metadata.csv not found, proceeding with defaults." << endl;
    }

    // go through all the sub-chunks of the input and
    // process the ones you care about
    
    tlDataChunk* outchunk = new tlDataChunk();
    
    for(int ch=0; ch < inchunk->SubChunkCount(); ch++)
        {
            // create the next sub-chunk
            tlDataChunk* sub = inchunk->GetSubChunk(ch);
            
            // look at the id of the subchunk to decide if we 
            // want to do something with it or not
            switch(sub->ID())
            {                  


            case Pure3D::Mesh::MESH:               
                {
                    
                    //printf("\n");
                    tlMeshChunk* p_mesh = (tlMeshChunk* )  sub;                                     
                    char mesh_name[max_length];
                    char full_mesh_name[max_length];
                    
                    //get object name and remove extra appended crap
                    ::rootname(p_mesh->GetName(),mesh_name);
                    // Keep the full mesh name for DSG creation (important for _Shape objects)
                    strcpy(full_mesh_name, p_mesh->GetName());                    
                                                    
                   
                    //lookup ArtDB for info on this mesh 
                    bool foundInMeta = false;
                    ObjectMetadata meta;
                    // First try normalized name
                    if (metadataMap.find(mesh_name) != metadataMap.end()) {
                        meta = metadataMap[mesh_name];
                        foundInMeta = true;
                    }
                    // Then try full mesh name (for _Shape objects)
                    else if (metadataMap.find(full_mesh_name) != metadataMap.end()) {
                        meta = metadataMap[full_mesh_name];
                        foundInMeta = true;
                    }
    
                    //check results, 
                    //if not found in ArtDB make it a  into a StaticEntityDSG as a default.
                    if (!foundInMeta)
                    {
                        //create StaticEntityDSG chunk and append mesh
                        printf("%s : Mesh not found in metadata creating EntityDSGChunk !\n",mesh_name);
                        printf("    DSG NAME: '%s' (full mesh name)\n", p_mesh->GetName());
                        tlEntityDSGChunk* p_entitydsg =new tlEntityDSGChunk();
                        p_entitydsg->SetName(p_mesh->GetName());
                        p_entitydsg->AppendSubChunk(sub,FALSE);
                        outchunk->AppendSubChunk(p_entitydsg,FALSE);
                        p_dsglist->AddDSG(p_entitydsg);

                    }
                    // its found in the ArtDB, need to determine what kind of DSG to make.          
                    else
                    {
        
                        {
                            const char* classtypeID = meta.ClassType.c_str();
                            printf("Found %s meshchunk in metadata \n",p_mesh->GetName());
                            //printf("Classtype ID: %s \n",classtypeID);

                           //make the correct DSG chunktype
                            if (
                                    (strcmp(classtypeID,"PROP_MOVEABLE")==0)                    ||
                                    (strcmp(classtypeID,"PROP_BREAKABLE")==0)                   ||
                                    (strcmp(classtypeID,"PROP_ONETIME_MOVEABLE")==0)
                                )
                            {
                                printf("    %s is of type %s creating DynaPhysDSGChunk \n",mesh_name,classtypeID);
                                printf("    DSG NAME: '%s' (full mesh name)\n", p_mesh->GetName());
                                tlDynaPhysDSGChunk* p_dynaphysdsg =new tlDynaPhysDSGChunk ();
                                p_dynaphysdsg->SetName(p_mesh->GetName());
                                p_dynaphysdsg->AppendSubChunk(sub,FALSE);
                                outchunk->AppendSubChunk(p_dynaphysdsg,FALSE);
                                p_dsglist->AddDSG(p_dynaphysdsg);
                                //printf("    Finished making chunk\n");
                            }
                           
                            else if (strcmp(classtypeID,"PROP_STATIC")==0)
                            {
                                printf("    %s is of type %s creating InstaStaticPhysDSGChunk \n",mesh_name,classtypeID);
                                tlInstaStaticPhysDSGChunk* p_instaphysdsg =new tlInstaStaticPhysDSGChunk ();
                                p_instaphysdsg->SetName(p_mesh->GetName());
                                p_instaphysdsg->AppendSubChunk(sub,FALSE);
                                outchunk->AppendSubChunk(p_instaphysdsg,FALSE);
                                p_dsglist->AddDSG(p_instaphysdsg);
                            }

                            else if (strcmp(classtypeID,"PROP_DRAWABLE")==0)
                            {
                                printf("    %s is of type %s creating InstaEntityDSGChunk \n",mesh_name,classtypeID);
                                tlInstaEntityDSGChunk* p_instaentitydsg =new tlInstaEntityDSGChunk();
                                p_instaentitydsg->SetName(p_mesh->GetName());
                                p_instaentitydsg->AppendSubChunk(sub,FALSE);
                                outchunk->AppendSubChunk(p_instaentitydsg,FALSE);
                                p_dsglist->AddDSG(p_instaentitydsg);
                            }

                            else if (strcmp(classtypeID,"STATIC")==0)
                            {
                                printf("    %s is of type %s creating EntityDSGChunk \n",mesh_name,classtypeID);
                                printf("    DSG NAME: '%s' (full mesh name)\n", p_mesh->GetName());
                                tlEntityDSGChunk* p_entitydsg =new tlEntityDSGChunk();
                                p_entitydsg->SetName(p_mesh->GetName());
                                p_entitydsg->AppendSubChunk(sub,FALSE);
                                outchunk->AppendSubChunk(p_entitydsg,FALSE);
                                p_dsglist->AddDSG(p_entitydsg);
                            }
                            
                            else if (strcmp(classtypeID,"DRAWABLE")==0)
                            {
                                printf("    %s is of type %s creating EntityDSGChunk \n",mesh_name,classtypeID);
                                printf("    DSG NAME: '%s' (full mesh name)\n", p_mesh->GetName());
                                tlEntityDSGChunk* p_entitydsg =new tlEntityDSGChunk();
                                p_entitydsg->SetName(p_mesh->GetName());
                                p_entitydsg->AppendSubChunk(sub,FALSE);
                                outchunk->AppendSubChunk(p_entitydsg,FALSE);
                                p_dsglist->AddDSG(p_entitydsg);
                            }
                            
                            else if (strcmp(classtypeID,"ANIMATED_BV")==0)
                            {
                                printf("    %s is of type %s creating AnimatedBvDSGChunk \n",mesh_name,classtypeID);

                                //Need to finalize class specs with Greg, Devin and Trav TBD still

                                //tlDynaPhysDSGChunk* p_dynaphysdsg =new tlDynaPhysDSGChunk ();
                                //p_dynaphysdsg->SetName(p_mesh->GetName());
                                //p_dynaphysdsg->AppendSubChunk(sub,FALSE);
                                outchunk->AppendSubChunk(sub,FALSE);
                            }
                            else 
                            {
                                printf("\n===================================================\n");
                                printf("\n=\tError unknown %s ClasstypeID \n",classtypeID);
                                printf("\n===================================================\n");
                            }
                                

                        }//end if

                    }//end else
                    //printf("exiting Mesh case\n");
                    break;
                }
            case Simulation::Physics::OBJECT:
                {
                    tlPhysicsObjectChunk *p_physobject = (tlPhysicsObjectChunk*) sub;
                    tlDataChunk* p_dsg=NULL;
                    char name[max_length];
                    char nameNoDigits[max_length];
                    
                    ::rootname(p_physobject->GetName(),name);
                    StripTrailingDigits(p_physobject->GetName(), nameNoDigits);
                    printf("\n");
                    printf("Phys Chunk: %s \n",p_physobject->GetName());

                    printf("Found instance chunk '%s' looking for parent DSG:\n", p_physobject->GetName());
                    printf("  Trying raw name: '%s'\n", p_physobject->GetName());
                    printf("  Trying no digits: '%s'\n", nameNoDigits);
                    printf("  Trying rootname: '%s'\n", name);

                    p_dsg =p_dsglist->GetDSG(p_physobject->GetName());

                    if( p_dsg ==NULL)
                    {
                        p_dsg=p_dsglist->GetDSG(nameNoDigits);
                    }

                    if( p_dsg ==NULL)
                    {
                        p_dsg=p_dsglist->GetDSG(name);
                    }

                    if( p_dsg ==NULL)
                    {
                        badart=true;
                        printf("\n===================================================\n");
                        printf("\n=\tERROR: Cant find Parent DSG for %s, This Physics Volume is MISSING its mesh!!\n",p_physobject->GetName());
                        printf("\n===================================================\n");
                    }
                    else
                    {
                        printf("    Found the parent for %s\n",p_physobject->GetName());
                        p_dsg->AppendSubChunk(sub,FALSE);
                    }
                    break;
                }


            case Simulation::Collision::OBJECT:
                {
                    //printf("entering Collision object \n");
                    //temp local variables

                    tlCollisionObjectChunk* p_collisionobject= (tlCollisionObjectChunk*)sub;
                    bv_data bv_object;
                    tlDataChunk* p_dsg=NULL;
					char sound [64] ="nosound"; //default vaule

                    bool errors =false;
                    char querybuffer [1000];
                                     
                    
                    ::rootname(p_collisionobject->GetName(),bv_object.name);
                    char nameNoDigits[max_length];
                    StripTrailingDigits(p_collisionobject->GetName(), nameNoDigits);
                    
                    printf("\n");
                    printf("BV name: %s \t ",p_collisionobject->GetName());
                    
                    //seting default vaules, 7 is the default for staticphysDSG's,
                    //and physprop 0 is bogus vaule and should get filled in if BV object is know in the artdb. 
                    bv_object.classtype=7;
                    bv_object.physpropid=0;                    
                    
                    bool foundInMeta = false;
                    ObjectMetadata meta;
                    if (metadataMap.find(bv_object.name) != metadataMap.end()) {
                        meta = metadataMap[bv_object.name];
                        foundInMeta = true;
                    }

                    if (foundInMeta)
                    {
                        const char* classtypeID = meta.ClassType.c_str();
                        bv_object.physpropid = meta.physpropid;
                        strcpy(sound, meta.Sound.c_str());

                        //make the correct DSG chunktype
                        if (strcmp(classtypeID,"PROP_MOVEABLE")==0)
                        {
                            printf("    %s is of type %s Setting Classtype to 3\n",bv_object.name,classtypeID);
                            bv_object.classtype=3;                            
                        }
                            
                        else if (strcmp(classtypeID,"PROP_BREAKABLE")==0)
                        {
                            printf("    %s is of type %s Setting Classtype to 4\n",bv_object.name,classtypeID);
                            bv_object.classtype=4;                            
                        }

                        else if (strcmp(classtypeID,"PROP_STATIC")==0)
                        {
                            printf("    %s is of type %s Setting Classtype to 2\n",bv_object.name,classtypeID);
                            bv_object.classtype=2;
                        }
                            
                        else if (strcmp(classtypeID,"DRAWABLE")==0)
                        {
                            printf("    %s is of type %s ERROR Drawable Objects DO NOT HAVE BV'S!!!\n",bv_object.name,classtypeID);
                            badart=true;
                        }
                        else if (strcmp(classtypeID,"PROP_DRAWABLE")==0)
                        {
                            printf("    %s is of type %s ERROR PROP_DRAWABLE Objects DO NOT HAVE BV'S!!!\n",bv_object.name,classtypeID);
                            badart=true;
                        }
                            
                        else if (strcmp(classtypeID,"ANIMATED_BV")==0)
                        {
                            printf("    %s is of type %s Setting Classtype to 5\n",bv_object.name,classtypeID);
                            bv_object.classtype=5;
                        }
                        else if (strcmp(classtypeID,"STATIC")==0)
                        {
                            printf("    %s is of type %s Setting Classtype to 2\n",bv_object.name,classtypeID);
                            bv_object.classtype=7;
                        }
                        else if (strcmp (classtypeID,"PROP_ONETIME_MOVEABLE")==0)
                        {
                            printf("    %s is of type %s Setting Classtype to 10\n",bv_object.name,classtypeID);
                            bv_object.classtype=10;
                        }



                    }//end meta check


                    
                    //creating object attribute chunk
                    tlObjectAttributeChunk* p_otc =new tlObjectAttributeChunk ();
                    p_otc->SetClassType(bv_object.classtype);
                    p_otc->SetPhyPropID(bv_object.physpropid);
					p_otc->SetSound(sound);

                    //if object is a static then create a StaticPhysDSGChunk
                    if(bv_object.classtype == 7)
                    {
                        tlStaticPhysDSGChunk* p_statdsg =new tlStaticPhysDSGChunk ();
                        p_statdsg->AppendSubChunk(sub,FALSE);
                        p_statdsg->AppendSubChunk(p_otc);
                        p_statdsg->SetName(p_collisionobject->GetName());
                        outchunk->AppendSubChunk(p_statdsg,FALSE);
                    }

                    //otherwise find the Parent DSG and add OTC and 
                    else
                    {
                        //printf("    Need to find Parent DSG \n");
                        // find the parent DynaDSG object
                        p_dsg=p_dsglist->GetDSG(p_collisionobject->GetName());

                        if(p_dsg ==NULL)
                        {
                            p_dsg=p_dsglist->GetDSG(nameNoDigits);
                        }

                        if(p_dsg ==NULL)
                        {
                            p_dsg=p_dsglist->GetDSG(bv_object.name);
                        }

                        if(p_dsg ==NULL)
                        {
                            printf("\n===================================================\n");
                            printf("\n=\tERROR: Cant Find Parent DSG for %s, This Bounding Volume is MISSING its Mesh!! \n",p_collisionobject->GetName());
                            printf("\n===================================================\n");
                            badart=true;
                        }
                        else
                        {
                            printf("    Found the parent for %s\n",p_collisionobject->GetName());
                            p_dsg->AppendSubChunk(p_otc,FALSE);
                            p_dsg->AppendSubChunk(sub,FALSE);
                        }              
                    }                   
                    //printf("exiting collision\n");
                    break;
                  }
                 
		
			case SRR2::ChunkID::ANIM_DSG_WRAPPER:
					  {
						  bv_data bv_object;
						  char sound[64] = "nosound"; //setting default vaule
						  char chunkname [64];							
						  

						  //tlAnimDSGWrapperChunk* p_animwrapper = dynamic_cast<tlAnimDSGWrapperChunk*>(sub);

						  printf("Found %s AnimWrapperChunk \n",sub->GetName());
						  ::rootname(sub->GetName(),chunkname);
						  
						  //query ArtDB for info on this instanced Animated object
						  bool foundInMeta = false;
						  ObjectMetadata meta;
						  if (metadataMap.find(chunkname) != metadataMap.end()) {
							  meta = metadataMap[chunkname];
							  foundInMeta = true;
						  }
						  

						  //check if animwrapper found in artDB
						  if (!foundInMeta)
						
						  {
							  //object not found in the art db
							  printf("	ERROR: Object not found in metadata,Skipping InstAnimDSGChuck Creation!\n");
							  break;
						  }
						  
						 
						  //getting the phys properties						
						  {            
							
							//set classtype to prop_breakable
							bv_object.classtype =4;
							bv_object.physpropid=meta.physpropid;
							strcpy(sound,meta.Sound.c_str());

						 }

						  printf("    %s is of type InstaAnimDynaPhysDSG creating InstaEntityDSGChunk \n",sub->GetName());

						   //create InstaAnimDSGChunk and OTC 						
						  tlInstAnimDynaPhysDSGChunk* p_instanimdsg = new tlInstAnimDynaPhysDSGChunk ();
						  tlObjectAttributeChunk* p_otc = new tlObjectAttributeChunk ();

						  //fill in data for the newly created chunks
						  p_instanimdsg->SetName(sub->GetName());
						  p_otc->SetClassType(bv_object.classtype);
						  p_otc->SetPhyPropID(bv_object.physpropid);
						  p_otc->SetSound(sound);

						  //append chunks into the InstaAnimDynaPhysDSGChunk
						  p_instanimdsg->AppendSubChunk(sub,FALSE);
						  p_instanimdsg->AppendSubChunk(p_otc,FALSE);						
						
						  //append InstaAnimDynaPhysDSGChunk to the outchunk
						  outchunk->AppendSubChunk(p_instanimdsg,FALSE);
						  p_dsglist->AddDSG(p_instanimdsg);

						  break;
					  }

            case SRR2::ChunkID::ANIM_OBJ_DSG_WRAPPER:
					  {
						  bv_data bv_object;
						  char sound[64] = "nosound"; //setting default vaule
						  char chunkname [64];							
						  

						  //tlAnimDSGWrapperChunk* p_animwrapper = dynamic_cast<tlAnimDSGWrapperChunk*>(sub);

						  printf("Found %s AnimObjWrapperChunk \n",sub->GetName());
						  ::rootname(sub->GetName(),chunkname);
						  
						  //query ArtDB for info on this instanced Animated object
						  bool foundInMeta = false;
						  ObjectMetadata meta;
						  if (metadataMap.find(chunkname) != metadataMap.end()) {
							  meta = metadataMap[chunkname];
							  foundInMeta = true;
						  }
						  

						  //check if animobjwrapper found in artDB
						  if (!foundInMeta)
						
						  {
							  //object not found in the art db
							  printf("	ERROR: Object not found in metadata,Skipping InstAnimDSGChuck Creation!\n");
							  break;
						  }
						  
						 
						  //getting the phys properties						
						  { 
                              
                                const char* classtypeID = meta.ClassType.c_str();
                                bv_object.physpropid=meta.physpropid;
						        strcpy(sound,meta.Sound.c_str());
                                strcpy(bv_object.name,sub->GetName());

                                //set the correct classtypeID
                                if (strcmp(classtypeID,"PROP_MOVEABLE")==0)
                                {
                                    printf("    %s is of type %s Setting Classtype to 3\n",bv_object.name,classtypeID);
                                    bv_object.classtype=3;                            
                                }
                            
                                else if (strcmp(classtypeID,"PROP_BREAKABLE")==0)
                                {
                                    printf("    %s is of type %s Setting Classtype to 4\n",bv_object.name,classtypeID);
                                    bv_object.classtype=4;                            
                                }

                                else if (strcmp(classtypeID,"PROP_STATIC")==0)
                                {
                                    printf("    %s is of type %s Setting Classtype to 2\n",bv_object.name,classtypeID);
                                    bv_object.classtype=2;
                                }
                            
                                else if (strcmp(classtypeID,"DRAWABLE")==0)
                                {
                                    printf("    %s is of type %s ERROR Drawable Objects DO NOT HAVE BV'S!!!\n",bv_object.name,classtypeID);
                                    badart=true;
                                }
                                else if (strcmp(classtypeID,"PROP_DRAWABLE")==0)
                                {
                                    printf("    %s is of type %s ERROR PROP_DRAWABLE Objects DO NOT HAVE BV'S!!!\n",bv_object.name,classtypeID);
                                    badart=true;
                                }
                            
                                else if (strcmp(classtypeID,"ANIMATED_BV")==0)
                                {
                                    printf("    %s is of type %s Setting Classtype to 5\n",bv_object.name,classtypeID);
                                    bv_object.classtype=5;
                                }
                                else if (strcmp(classtypeID,"STATIC")==0)
                                {
                                    printf("    %s is of type %s Setting Classtype to 2\n",bv_object.name,classtypeID);
                                    bv_object.classtype=7;
                                }

                                else if (strcmp(classtypeID,"PROP_ANIM_BREAKABLE")==0)
                                {
                                    printf("    %s is of type %s Setting Classtype to 9 \n",bv_object.name,classtypeID);
                                    bv_object.classtype=9;
                                }
                                
                                else if (strcmp(classtypeID,"PROP_ONETIME_MOVEABLE")==0)
                                {
                                    printf("    %s is of type %s Setting Classtype to 10\n",bv_object.name,classtypeID);
                                    bv_object.classtype=10;
                                }
							    
							    
							   
                          }//end meta check

						  printf("    %s is of type InstaAnimDynaPhysDSG creating InstaAnimDynaPhysDSGChunk \n",sub->GetName());

						   //create InstaAnimDSGChunk and OTC 						
						  tlInstAnimDynaPhysDSGChunk* p_instanimdsg = new tlInstAnimDynaPhysDSGChunk ();
						  tlObjectAttributeChunk* p_otc = new tlObjectAttributeChunk ();

						  //fill in data for the newly created chunks
						  p_instanimdsg->SetName(sub->GetName());
						  p_otc->SetClassType(bv_object.classtype);
						  p_otc->SetPhyPropID(bv_object.physpropid);
						  p_otc->SetSound(sound);

						  //append chunks into the InstaAnimDynaPhysDSGChunk
						  p_instanimdsg->AppendSubChunk(sub,FALSE);
						  p_instanimdsg->AppendSubChunk(p_otc,FALSE);						
						
						  //append InstaAnimDynaPhysDSGChunk to the outchunk
						  outchunk->AppendSubChunk(p_instanimdsg,FALSE);
						  p_dsglist->AddDSG(p_instanimdsg);

						  break;
					  }


            case SRR2::ChunkID::INSTANCES:
                      {
                          tlDataChunk* p_dsg=NULL;
                          tlDataChunk* subchunk= sub->GetSubChunk(0);
                          tlScenegraphChunk* p_scenegraphchunk= dynamic_cast<tlScenegraphChunk *>(subchunk);
                          char rootName[max_length];
                          char nameNoDigits[max_length];

                          printf("\n");
                          printf("Found %s instance chunk,looking for Parent DSG.\n",p_scenegraphchunk->GetName());

                          ::rootname(p_scenegraphchunk->GetName(), rootName);
                          StripTrailingDigits(p_scenegraphchunk->GetName(), nameNoDigits);
                          
                          printf("  Trying raw name: '%s'\n", p_scenegraphchunk->GetName());
                          printf("  Trying no digits: '%s'\n", nameNoDigits);
                          printf("  Trying rootname: '%s'\n", rootName);

                          p_dsg=p_dsglist->GetDSG(p_scenegraphchunk->GetName());

                          if(p_dsg ==NULL)
                          {
                              p_dsg=p_dsglist->GetDSG(nameNoDigits);
                          }

                          if(p_dsg ==NULL)
                          {
                              p_dsg=p_dsglist->GetDSG(rootName);
                          }

                          if(p_dsg ==NULL)
                          {      
                                printf("\n===================================================\n");
                                printf("\n=\tERROR: Cant Find Parent DSG Chunk for %s, SceneGraph is MISSING its Mesh!! \n",p_scenegraphchunk->GetName());
                                printf("\n===================================================\n");
                                badart=true;
                           }
                          else
                          {
                                printf("    Found the parent for %s\n",p_scenegraphchunk->GetName());
                                p_dsg->AppendSubChunk(sub,FALSE);
                          }
                          break;                          
                      }
                      
            default:
                 {
                    // this is not a chunk that we care about
                    // so simply copy it to the output wrapper chunk
                    // the optional parameter to AppendSubChunk
                    // indicates that we have merely copied a pointer
                    // so the destructor of outchunk should not
                    // destroy this sub-chunk as that duty will be
                    // taken care of by the destructor of inchunk
                    outchunk->AppendSubChunk(sub,FALSE);
                    break;
                 }
            }//end switch
        }//end for
        
        p_dsglist->ReSortDSGChunks();

        if ( mbIgnoreMissingInstanceChunk == true)
        {
            p_dsglist->mbNoInstanceChunks = true;
            //printf("Ignore chunk is set!\n");
        }
        
        // Debug: Print all DSG names before verification
        printf("\n=== ALL CREATED DSG CHUNKS ===\n");
        for(unsigned int i = 0; i < p_dsglist->GetIndexCount(); i++) {
            tlDataChunk* dsg = p_dsglist->GetDSGByIndex(i);
            if(dsg) {
                printf("DSG[%d]: '%s'\n", i, dsg->GetName());
            }
        }
        printf("================================\n\n");
        
        if(p_dsglist->VerifyChunks() == 1)
        {
            badart=true;
        }



    /*
    catch (std::exception& er)
    {
        cout<<"Error: " <<er.what()<< endl;
        return 1;
    }
    */
    
    if (badart)
    {     
      
        printf("\n=======================================================\n");
        printf("\n=\tERROR: %s is missing Chunks for DSG objects Aborting DSG Prop Creation !!! \n",filename);
        printf("\n=======================================================\n");

/*        
        // create the new output file
        tlFile output(new tlFileByteStream(filename, omWRITE), tlFile::CHUNK32);

        if(!output.IsOpen()) 
        {
            printf("Could not open %s for writing,unable to Save\n", filename);
            exit(-1);
        }

        // get the output wrapper chunk to write its data out
        // to the file
        outchunk->Write(&output);
*/
        delete inchunk;
        delete outchunk;
        delete p_dsglist;
        return 1;
    }
    else
    {
        
        printf("\n=======================================================\n");
        printf("\n=\tDSGmaker: Completed without ERRORS \n");
        printf("\n=======================================================\n");

        // create the new output file
        tlFile output(new tlFileByteStream(filename, omWRITE), tlFile::CHUNK32);

        if(!output.IsOpen()) 
        {
            printf("Could not open %s for writing\n", filename);
            exit(-1);
        }

        // get the output wrapper chunk to write its data out
        // to the file  
        outchunk->Write(&output);
         
        // cleanup the no-longer-needed  chunks
        delete inchunk;
        delete outchunk;
        delete p_dsglist;


        return 0;
    }
} //end of main



/********************************************************************/                                                                                                      
/* Helper Function to strip extra crap from the string                                         */
/********************************************************************/


unsigned int  rootname(const char * input,char* output)
{
     char source_name[max_length];
     char object_name1[max_length];
     char object_name2[max_length];
     char* token =NULL;

     //printf("Phase 1 get name \n");
                                    
     //get the name of collision object
     strcpy(source_name,input);
     //cout<<"Source name: "<<source_name<<endl;
                   
     //printf("smashing %s\n",source_name);
     //smash up string to remove the number appended by Maya
     //printf("strtok1\n");
     token=strtok(source_name,"_");
     strcpy(object_name1,token);
     //printf("After stringtok :%s \n",object_name1);

     //printf("strcat1\n");
     //reform string
     strcat(object_name1,"_");
     
     
     //printf("strtok2\n");
     token=strtok(NULL,"_");
     
     if(token != NULL)
     {
        strcpy(object_name2,token);
        //printf("After stringtok :%s \n",object_name2);            
       // printf("strcat2\n");
        strcat(object_name1,object_name2);
     }
       
     //printf("strcpy\n");
     //set default vaules 

     strcpy(output,object_name1);
     //printf("processed name : %s\n",output);
     return 0;
}

