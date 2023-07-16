# add-nbo

Usage
```
echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
make
./add-nbo [file1] [file2]
```