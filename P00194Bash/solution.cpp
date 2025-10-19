#Read from the file file.txt and print its transposed content to stdout.

seq 1 $(head - 1 file.txt | wc - w) |
    xargs - I '{}' bash - c "cut -d '" ' ' "' -f {} file.txt| xargs"
