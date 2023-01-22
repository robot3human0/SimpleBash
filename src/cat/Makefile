all: build

build: study_cat

study_cat:
	gcc -std=c11 -Wall -Werror -Wextra study_cat.c -o study_cat

clean:
	rm -rf study_cat

rebuild: clean all

test:
	cat ../test/rubai.txt > ../test/txt1.txt && ./study_cat ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat ../test/rubai.txt study_cat.h > ../test/txt1.txt && ./study_cat ../test/rubai.txt study_cat.h > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat -b ../test/rubai.txt > ../test/txt1.txt && ./study_cat -b ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat -e ../test/rubai.txt > ../test/txt1.txt && ./study_cat -e ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat -n ../test/rubai.txt > ../test/txt1.txt && ./study_cat -n ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat -s ../test/rubai.txt > ../test/txt1.txt && ./study_cat -s ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat -t ../test/rubai.txt > ../test/txt1.txt && ./study_cat -t ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat -v ../test/bytes.txt > ../test/txt1.txt && ./study_cat -v ../test/bytes.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt

test_linux:
	cat ../test/rubai.txt > ../test/txt1.txt && ./study_cat ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat ../test/rubai.txt study_cat.h > ../test/txt1.txt && ./study_cat ../test/rubai.txt study_cat.h > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat --number-nonblank ../test/rubai.txt > ../test/txt1.txt && ./study_cat --number-nonblank ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat --show-ends ../test/rubai.txt > ../test/txt1.txt && ./study_cat --show-ends ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat --number ../test/rubai.txt > ../test/txt1.txt && ./study_cat --number ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat --squeeze-blank ../test/rubai.txt > ../test/txt1.txt && ./study_cat --squeeze-blank ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat --show-tabs ../test/rubai.txt > ../test/txt1.txt && ./study_cat --show-tabs ../test/rubai.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat --show-nonprinting ../test/bytes.txt > ../test/txt1.txt && ./study_cat --show-nonprinting ../test/bytes.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat -e ../test/bytes.txt > ../test/txt1.txt && ./study_cat -e ../test/bytes.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt
	cat -t ../test/bytes.txt > ../test/txt1.txt && ./study_cat -t ../test/bytes.txt > ../test/txt2.txt && diff ../test/txt1.txt ../test/txt2.txt

