# Simpsons-Hit-And-Run-Fixed

This project seeks to make all the platforms and projects build, Win32, PS2, Gamecube, Xbox Original and Art project and to port to other platforms.

# Please read me

As ssr2test database wasnt leaked, this project is almost impossible, please, if you can somehow obtain it or have contacts to old employees at radical of know the original leaker, please pass the contacts or anything to get the database contents.


# Status
- [x] Win32 - Works and builds fine, Debug and Release tested on 140_xp toolchain.
- [ ] PS2 - Builds fine but cant be tested because Art doesnt build fully. 
- [ ] Gamecube - Doesnt build fully.
- [ ] Xbox - Not tested at all.
- [ ] Art - Everything builds and works except anything related to Levels or where DSGMaker or atcmaker is used.

## Notes
- Since Logitect Wheel SDKs havent been discovered for either PS2 or Gamecube, code exclusions will be added as guards (RAD_"PLATFORM"_WHEEL) but not removed.
  
- Since the ssr2test database contents werent leaked, levels cant be rebuilt properly, i tried trying to make a tool for somehow fetching then from built PC assets into csv and then getting DSGMaker to use the csv as the reference but unsuccessfuly. If an dev or leaker could pass the database dump, it would really mean a lot.



