#rm clean1.txt
cat ../wlist_all/wlist_match1.txt | grep -E '^.{3,15}$' | grep -E "^[a-zA-Z]*$" | uniq > clean1.txt
shuf clean1.txt >> shuffled1.txt