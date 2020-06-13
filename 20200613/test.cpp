#include <iostream>
#include <string>
using namespace std;

template<class T>
struct ListNode {
	T _value;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_value(val)
		,_next(nullptr)
		,_prev(nullptr)
	{}
};

template<class T>
class List {
public:
	typedef ListNode<T> Node;

	List()
		:_header(new Node)
	{
		//构建循环结构
		_header->_next = _header->_prev = _header;
	}
	//尾插
	void pushBack(const T& val) {
		Node* cur = new Node(val);
		Node* prev = _header->_prev;

		prev->_next = cur;
		cur->_prev = prev;

		cur->_next = _header;
		_header->_prev = cur;
	}
private:
	Node* _header;
};