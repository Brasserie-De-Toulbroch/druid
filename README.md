# Druid

<p align="center">
  <img src="https://github.com/Brasserie-De-Toulbroch/druid/blob/master/docs/druid.png" width="500" title="Druid">
</p>

## Hook

Pre-commit hook:

````
$ ln -s ../../scripts/pre-commit-clang-format .git/hooks/pre-commit
````

## Cross-Compiling

Cross-compiling for RPI3 with `https://github.com/Brasserie-De-Toulbroch/buildroot-rpi3`:

````
$ mkdir build
$ cd build
$ cmake -DCMAKE_TOOLCHAIN_FILE=../arm-toolchain.cmake
$ make
````
