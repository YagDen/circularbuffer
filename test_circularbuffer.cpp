#include "circular_buffer.h"
#include <iostream>
#include <string.h>
struct test_struct{
	int i;
	static int count ;
	char* bytes =nullptr; 
	test_struct(){
		i=0;
		bytes = (char*)malloc(10000000);
		std::cout<<"constructing test_struct: "<<count++<<"\n";
		}
	~test_struct(){
		std::cout<<"destructing test_struct\n";
		free(bytes);
	}
	};

int test_struct::count =0;
int main(int argc, char *argv[])
{   
	
	
    CircularBuffer<int> test{5};
	//std::cout<<"size of data "<<sizeof(data[1].bytes)<<"\n";
	std::cout<<"length of buffer "<<test.size()<<"\n";
	std::cout<<"size of buffer in bytes "<<test.buffer_size()<<"\n";
	std::cout<<"Max capacity  of buffer "<<test.capacity()<<"\n";
	std::cout<<"Checking is buffer empty function "<<test.empty()<<"\n";
	std::cout<<"Pushing back  data in bufffer \n";
	test.push_back(5);
	test.push_back(2);
	//test.push_back(3);
	std::cout<<"Checking is buffer empty function "<<test.empty()<<"\n";
	std::cout<<"Checking length of buffer after modification "<<test.size()<<"\n";
	std::cout<<"Checking front function  "<<test.front()<<"\n";
	std::cout<<"Checking front function  "<<test.front()<<"\n";
	std::cout<<"Checking back function  "<<test.back()<<"\n";
	test.back() = 10;
	
	std::cout<<"Checking pop function\n";
	test.pop_front();
	std::cout<<"Checking front function  "<<test.front()<<"\n";
	std::cout<<"Checking back function  "<<test.back()<<"\n";
	//std::cout<<"Checking []operator  "<<test[10]<<"\n";

	CircularBuffer<std::string> test_stringbuf{10};
	std::cout<<"Checking is buffer empty function "<<test_stringbuf.empty()<<"\n";
	std::cout<<"Checking length of string buffer "<<test_stringbuf.size()<<"\n";
	std::cout<<"size of buffer in bytes "<<test_stringbuf.buffer_size()<<"\n";
	std::cout<<"Max capacity  of buffer "<<test_stringbuf.capacity()<<"\n";
	
	std::cout<<"Pushing back  data in bufffer \n";
	test_stringbuf.push_back("this is the first string");	
	test_stringbuf.push_back("this is the second string");
	test_stringbuf.push_back("this is the third string"); 

	std::cout<<"Checking is buffer empty function "<<test_stringbuf.empty()<<"\n";
	std::cout<<"Checking length of buffer after modification "<<test_stringbuf.size()<<"\n";
	std::cout<<"Checking front function  "<<test_stringbuf.front()<<"\n";
	std::cout<<"Checking back function  "<<test_stringbuf.back()<<"\n";
	test_stringbuf.pop_front();
	test_stringbuf.pop_front();
	std::cout<<"Checking length of buffer after modification "<<test_stringbuf.size()<<"\n";
	std::cout<<"Checking front function  "<<test_stringbuf.front()<<"\n";
	std::cout<<"Checking back function  "<<test_stringbuf.back()<<"\n";
	//while(true){}
    return 0;
}