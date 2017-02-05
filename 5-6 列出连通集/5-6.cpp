//5 - 6 列出连通集(25分)
//
//给定一个有 N 个顶点和 E 条边的无向图，请用DFS和BFS分别列出其所有的连通集。
//假设顶点从 0 到 N - 1 编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
//
//输入格式 :
//输入第1行给出2个整数 N (0 < N <= 10) 和 E，分别是图的顶点数和边数。
//随后E行，每行给出一条边的两个端点。每行中的数字之间用一空格分隔。
//
//输出格式 :
//按照"{v1 v2 ... vk}"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

//输入样例:
//8 6
//0 7
//0 1
//2 0
//4 1
//2 4
//3 5
//
//输出样例:
//{ 0 1 4 2 7 }
//{ 3 5 }
//{ 6 }
//{ 0 1 2 7 4 }
//{ 3 5 }
//{ 6 }

//时空限制: 400ms 64MB
/*-----------------------------------------------------------------------------------------------------------------*/

//思路：既然要“从编号最小的点出发，按编号递增的顺序访问”，而且数据规模很小，用邻接表是很好的选择。
//图和队列试着写成class

//已AC 用时：2ms

#include <iostream>
#define SIZE 10

using namespace std;

struct arr{
	int size = 0;
	int data[SIZE] = { 0 };
	void output() {
		cout << '{';
		for (int i = 0; i < size; i++) {
			cout << ' ' << data[i];
		}
		cout << " }" << endl;
	}
	void clear() {
		size = 0;
		for (int i = 0; i < SIZE; i++) {
			data[i] = 0;
		}
	}
};

class node {
private:
	arr link;
public:
	void addLink(int num) {
		int i = link.size - 1;
		while (link.data[i] > num && i >= 0) {
			link.data[i + 1] = link.data[i];
			i--;
		}
		link.data[i + 1] = num;
		link.size++;
	}; 
	int getNthLink(int n) {
		return link.data[n];
	}
	int getLinksNum() {
		return link.size;
	}
};

class queue {
private:
	int& head = que.size;
	int tail = 0;
	arr que;
public:
	int pop() {
		int ret = que.data[tail];
		tail++;
		return ret;
	}
	void append(int num) {
		que.data[head] = num;
		head++;
	}
	bool isEmpty() {
		return head == tail;
	}
};

class graph{
private:
	bool visited[SIZE] = { false };
	node nodeList[SIZE];
	int N, E;
public:
	void link(int n1, int n2) {
		nodeList[n1].addLink(n2);
		nodeList[n2].addLink(n1);
	}
	void build() {
		cin >> N >> E;
		for (int i = 0; i < E; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			link(n1, n2);
		}
	};
	arr* DFSconnect(int start) {
		arr* visitList = new arr;
		visitList->size = 1;
		visitList->data[0] = start;
		visited[start] = true;
		for (int i = 0; i < nodeList[start].getLinksNum(); i++) {
			if (!visited[nodeList[start].getNthLink(i)]) {
				arr* newVisit = DFSconnect(nodeList[start].getNthLink(i));
				for (int j = 0; j < newVisit->size; j++) {
					int& tail = visitList->size;
					visitList->data[tail++] = newVisit->data[j];
				}
			}
		}
		return visitList;
	};
	arr* BFSconnect(int start) {
		arr* visitList = new arr;
		queue que;
		que.append(start);
		visited[start] = true;
		while (!que.isEmpty()) {
			int now = que.pop();
			for (int i = 0; i < nodeList[now].getLinksNum(); i++) {
				int nextNode = nodeList[now].getNthLink(i);
				if (!visited[nextNode]) {
					que.append(nextNode);
					visited[nextNode] = true;
				}
			}
			visitList->data[visitList->size++] = now;
		}
		return visitList;
	};
	void solve(int times) {
		for (int i = 0; i < N; i++) {
			visited[i] = false;
		}
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				if (times == 1) {
					DFSconnect(i)->output();
				}
				else if (times == 2) {
					BFSconnect(i)->output();
				}
			}
		}
		if (times == 1) solve(2);
	};
};

int main() {
	graph G;
	G.build();
	G.solve(1);
	return 0;
}

/*-----------------------------------------------------------------------------------------------------------------*/
//后记：写这玩意用C++写辣么长，有种杀鸡用牛刀的感觉
//更何况我还不会用牛刀
//
//确实，这种代码可维护性和可复用性很高，但写起来实在是很耗精力。我要不断地猜测我半个小时之后大概需要个什么借口。。。
//全当是练习C++了
//
