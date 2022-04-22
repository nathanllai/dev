test_list_doubly_linked: test_list_doubly_linked.cc
	g++ =Wall -Werror -std=c++11 -o test_list_doubly_linked test_list_doubly_linked.cc -lgtest -pthread

test: test_list_doubly_linked
	./test_list_doubly_linked