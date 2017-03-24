#include <iostream>
#include <vector>

using namespace std;

#define MAXNUM 100000

struct Node
{
	int address;
	int data;
	int next;
	void input();
	void output() const;
	bool isTail() const;
};

void Node::input()
{
	cin >> address >> data >> next;
}

void Node::output() const
{
	if (!isTail())
	{
		printf("%05d %d %05d\n", address, data, next);
	}
	else
	{
		printf("%05d %d %d\n", address, data, next);
	}
}

bool Node::isTail() const
{
	bool ret;
	ret = next == -1;
	return ret;
}

int main()
{
	vector<Node> NodeList(MAXNUM + 1);
	int head;
	int num;
	int k;

	Node temp;
	cin >> head >> num >> k;
	for (int i = 0; i < num; i++)
	{
		temp.input();
		NodeList[temp.address] = temp;
	}

	NodeList[num] = {num, 0, head};
	Node &HeadNode = NodeList[num];
	Node TailNode = {-1, 0, 0};
	int NodeNum;

	Node NowNode = HeadNode;

	for (NodeNum = 1; ; NodeNum++)
	{
		NowNode = NodeList[NowNode.next];
		if (NowNode.isTail())
		{
			break;
		}
	}
	NowNode = HeadNode;

	for (int i = 0; i < NodeNum / k; i++)
	{
		vector<int> AddressList(k + 2);
		for (int j = 0; j < k + 2; j++)
		{
			AddressList[j] = NowNode.address;
			NowNode = NowNode.isTail() ? TailNode : NodeList[NowNode.next];
		}

		NodeList[AddressList[0]].next = AddressList[k];
		for (int j = k; j > 1; j--)
		{
			NodeList[AddressList[j]].next = AddressList[j - 1];
		}
		NodeList[AddressList[1]].next = AddressList[k + 1];

		NowNode = NodeList[AddressList[1]];
	}

	NowNode = HeadNode;
	while (!NowNode.isTail())
	{
		NowNode = NodeList[NowNode.next];
		NowNode.output();
	}

	return 0;
}
