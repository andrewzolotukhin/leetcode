# Read from the file words.txt and output the word frequency list to stdout.

cat words.txt | tr '\n' ' ' | tr -s ' ' | tr ' ' '\n' | sort | uniq -c | sort -nr | awk '{print $2, $1}'
