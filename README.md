# SpatialC
A low level programming language frontend for LLPM


# Build Instructions:
- Make sure LLPM is built and working with the source dir at ../llpm
- cd grammar; ./build.sh; cd..
- scons

Parser in grammar dir must be rebuilt manually since I haven't figured out the
right way to create a scons builder for it. Yes, it must be possible and easy.
Yes, I am lazy and stupid.
