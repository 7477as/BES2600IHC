TARGET_PRJ=stdf
make T=$TARGET_PRJ REL_BUILD=1 -j all lst
python3 ./tools/generate_py3_crc32_of_image.py ./out/$TARGET_PRJ/${TARGET_PRJ}.bin
