#include "Tree.h"
#include <cstring>
#include <iostream>
#include <string>

int main()
{
	Tree tree, tree2, tree3, tree4;
	char word[] = "abcdfgh";
	char word2[] = "abcde";
	char word3[] = "sdfafd";
	char word4[] = "sdfsfd";
	char word5[] = "csdlhfs";
	tree.insert(word, strlen(word), 1000);
	tree.insert(word2, strlen(word2), 2000);
	tree.insert(word3, strlen(word3), 3000);
	tree.insert(word4, strlen(word4), 4000);
	tree.insert(word, strlen(word), 5000);
	tree.search(word, strlen(word));
	tree.wordCmp(word5, strlen(word5));
	std::cout << std::endl;

	char word_1[] = "ab";
	char word_2[] = "abc";
	char word_3[] = "abcdefg";
	char word_4[] = "c";
	char word_5[] = "abef";
	char word_6[] = "bcd";
	char word_7[] = "ede";
	char word_8[] = "bef";
	char word_9[] = "b";
	char word_10[] = "abcdef";
	char word_11[] = "bce";
	char word_12[] = "";
	char word_13[] = "abf";
	char word_14[] = "abceg";
	char word_15[] = "a";
	char del_word_1[] = "a";
	char del_word_2[] = "fgh";
	char del_word_3[] = "abcdefg";
	char del_word_4[] = "abef";
	char del_word_5[] = "bcd";
	tree2.insert(word_1, strlen(word_1), 1000);
	tree2.insert(word_2, strlen(word_2), 2000);
	tree2.insert(word_3, strlen(word_3), 3000);
	tree2.insert(word_4, strlen(word_4), 4000);
	tree2.insert(word_5, strlen(word_5), 5000);
	tree2.insert(word_6, strlen(word_6), 6000);
	tree2.insert(word_7, strlen(word_7), 7000);
	tree2.insert(word_8, strlen(word_8), 8000);
	tree2.insert(word_13, strlen(word_13), 13000);
	tree2.insert(word_15, strlen(word_15), 15000);
	tree2.search(word_1, strlen(word_1));
	tree2.search(word_2, strlen(word_2));
	tree2.search(word_3, strlen(word_3));
	tree2.search(word_4, strlen(word_4));
	tree2.search(word_5, strlen(word_5));
	tree2.search(word_6, strlen(word_6));
	tree2.search(word_7, strlen(word_7));
	tree2.search(word_8, strlen(word_8));
	tree2.search(word_9, strlen(word_9));
	tree2.search(word_10, strlen(word_10));
	tree2.search(word_11, strlen(word_11));
	tree2.search(word_12, strlen(word_12));
	tree2.wordCmp(word_14, strlen(word_14));
	tree2.remove(del_word_1, strlen(del_word_1));
	tree2.remove(del_word_2, strlen(del_word_2));
	tree2.remove(del_word_3, strlen(del_word_3));
	tree2.remove(del_word_4, strlen(del_word_4));
	tree2.remove(del_word_5, strlen(del_word_5));
	std::cout << std::endl;

	char tree3_1[] = "mother";
	char tree3_2[] = "moto";
	char tree3_3[] = "motor";
	char tree3_4[] = "mota";
	char tree3_5[] = "africa";
	char tree3_6[] = "string";
	char tree3_7[] = "strong";
	char tree3_cmp1[] = "para";
	char tree3_cmp2[] = "mo";
	char tree3_cmp3[] = "mothera";
	char tree3_cmp4[] = "mothe";
	char tree3_cmp5[] = "m";
	tree3.insert(tree3_1, strlen(tree3_1), 1000);
	tree3.insert(tree3_2, strlen(tree3_2), 2000);
	tree3.insert(tree3_3, strlen(tree3_3), 3000);
	tree3.insert(tree3_4, strlen(tree3_4), 4000);
	tree3.insert(tree3_5, strlen(tree3_5), 5000);
	tree3.insert(tree3_6, strlen(tree3_6), 6000);
	tree3.insert(tree3_7, strlen(tree3_7), 7000);
	tree3.wordCmp(tree3_cmp1, strlen(tree3_cmp1));
	std::cout << std::endl;
	tree3.wordCmp(tree3_cmp2, strlen(tree3_cmp2));
	std::cout << std::endl;
	tree3.wordCmp(tree3_cmp3, strlen(tree3_cmp3));
	std::cout << std::endl;
	tree3.wordCmp(tree3_cmp4, strlen(tree3_cmp4));
	std::cout << std::endl;
	tree3.wordCmp(tree3_cmp5, strlen(tree3_cmp5));
	std::cout << std::endl;

	tree4.insert("a", strlen("a"), 1000);
	tree4.insert("bcd", strlen("bcd"), 2000);
	tree4.remove("a", strlen("a"));
	tree4.remove("bcd", strlen("bcd"));
    return 0;
}