#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<numeric>

int count = 0;

struct Tree {
	Tree(long long key) {
		this->key = key;
	}

	Tree* left = nullptr;
	Tree* right = nullptr;
	long long key;
};

class BinTree {
public:
	BinTree() {
		first = nullptr;
	}

	~BinTree() {
	}

private:
	Tree* first;

public:
	Tree* getFirst();
	int deleteElement(long long keyDel);
	void inset(long long key);
};

Tree* BinTree::getFirst() {
	return first;
}

int BinTree::deleteElement(long long keyDel) {
	Tree* startKeyParent = nullptr;
	Tree* startKey = first;

	while (startKey) {
		if (startKey->key == keyDel) {
			break;
		}
		else if (keyDel < startKey->key) {
			startKeyParent = startKey;
			startKey = startKey->left;
		}
		else if (keyDel > startKey->key) {
			startKeyParent = startKey;
			startKey = startKey->right;
		}
	}

	if (startKey == nullptr) {
		return -1;
	}


	if (!startKey->left && !startKey->right) {
		if (startKeyParent->left == startKey) {
			startKeyParent->left = nullptr;
		}
		else {
			startKeyParent->right = nullptr;
		}
		delete(startKey);
	}
	else if (!startKey->right) {
		Tree* temp = startKey->left;
		startKey->key = temp->key;
		startKey->right = temp->right;
		startKey->left = temp->left;
		delete(temp);
	}
	else if (!startKey->left) {
		Tree* temp = startKey;
		startKey->key = temp->key;
		startKey->left = temp->left;
		startKey->right = temp->right;
		delete(temp);
	}
	else {
		Tree* min = startKey->right;
		Tree* minParent = startKey;

		while (min->left) {
			minParent = min;
			min = min->left;
		}
		startKey->key = min->key;

		if (min->right) {
			min->key = min->right->key;
			min->left = min->right->left;
			min->right = min->right->right;
		}
		else {

			if (minParent->left == min) {
				minParent->left = nullptr;
			}
			else {
				minParent->right = nullptr;
			}
			delete(min);
		}

	}

	return 0;
}

void BinTree::inset(long long key) {
	Tree** temp = &first;
	while (*temp) {
		Tree& node = **temp;

		if (key < node.key) {
			temp = &node.left;
		}
		else if (key > node.key) {
			temp = &node.right;
		}
		else {
			return;
		}
	}
	*temp = new Tree(key);
}

void show(Tree* v, std::ofstream& out) {
	if (v) {
		count--;
		out << v->key;
		if (count != 0) {
			out << std::endl;
		}

		show(v->left, out);
		show(v->right, out);
	}
}

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	std::string line;

	BinTree tree;
	long long keyDel;

	std::getline(in, line);
	keyDel = std::stoll(line);
	std::getline(in, line);


	while (std::getline(in, line)) {
		tree.inset(std::stoll(line));
		count++;
	}

	tree.deleteElement(keyDel);
	show(tree.getFirst(), out);

	out.close();
	in.close();
	return 0;
}