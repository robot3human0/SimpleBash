all: build
	
build: study_grep

study_grep:
	gcc -Wall -Werror -Wextra study_grep.c -o study_grep

clean:
	rm -rf study_grep

rebuild: clean all

test:
	grep okay ../test/ok_song.txt > ../test/txt1.txt && ./study_grep okay ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -e held ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -e held ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -i Okay ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -i Okay ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -v okay ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -v okay ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -c okay ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -c okay ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -l okay ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -l okay ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -n okay ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -n okay ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -h you ../test/ok_song.txt ../test/charches.txt > ../test/txt1.txt && ./study_grep -h you ../test/ok_song.txt ../test/charches.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -s okay ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -s okay ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -f ../test/rex.txt ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -f ../test/rex.txt ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -o okay ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -o okay ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -hf ../test/rex.txt ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -hf ../test/rex.txt ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -iv you ../test/ok_song.txt ../test/charches.txt > ../test/txt1.txt && ./study_grep -iv you ../test/ok_song.txt ../test/charches.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -il you ../test/ok_song.txt ../test/charches.txt > ../test/txt1.txt && ./study_grep -il you ../test/ok_song.txt ../test/charches.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -nv you ../test/ok_song.txt ../test/charches.txt > ../test/txt1.txt && ./study_grep -nv you ../test/ok_song.txt ../test/charches.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -ine you ../test/ok_song.txt > ../test/txt1.txt && ./study_grep -ine you ../test/ok_song.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -ine you ../test/ok_song.txt ../test/charches.txt > ../test/txt1.txt && ./study_grep -ine you ../test/ok_song.txt ../test/charches.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -ice you ../test/ok_song.txt ../test/charches.txt > ../test/txt1.txt && ./study_grep -ice you ../test/ok_song.txt ../test/charches.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -ivne you ../test/ok_song.txt ../test/charches.txt > ../test/txt1.txt && ./study_grep -ivne you ../test/ok_song.txt ../test/charches.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	grep -no you ../test/ok_song.txt ../test/charches.txt > ../test/txt1.txt && ./study_grep -no you ../test/ok_song.txt ../test/charches.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt

