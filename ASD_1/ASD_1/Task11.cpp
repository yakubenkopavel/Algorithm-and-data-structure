#include<iostream>
#include<string>
#include<fstream>
#include<set>

int count = 0;
int maxRootKey = 0;
int pas = 1;

int less = 0;
int more = 0;
int extraLess = 0;
int extraMore = 0;

struct Tree {
	Tree(long long key) {
		this->key = key;
	}

	Tree* left = nullptr;
	Tree* right = nullptr;
	int level = NULL;
	int sumChild = NULL;
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
		startKey->level = temp->level;
		startKey->sumChild = temp->sumChild;
		startKey->right = temp->right;
		startKey->left = temp->left;
		delete(temp);
	}
	else if (!startKey->left) {
		Tree* temp = startKey->right;
		startKey->key = temp->key;
		startKey->level = temp->level;
		startKey->sumChild = temp->sumChild;
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
			min->level = min->right->level;
			min->sumChild = min->right->sumChild;
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

long long walkTree(Tree* v) {
	long long median = 0;
	while (v) {
		median = v->key;
		if (v->left == nullptr) {
			less--;
			v = v->right;
		}
		else if (v->right == nullptr) {
			more--;
			v = v->left;
		}
		else {
			if (v->left->level < v->right->level) {
				less--;
				v = v->right;
			}
			else {
				more--;
				v = v->left;
			}
		}

		if (less == -1 || more == -1) {
			break;
		}
	}
	return median;

}

long long* walkTreeParent(Tree* v, int stop, int key) {
	long long* arrays = new long long[2];
	int i = 0;

	if (key > 0) {
		if ((stop - 1) == 0) {
			arrays[0] = v->key;
		}
		v = v->right;
		i++;
	}
	else if (key < 0) {
		if ((stop - 1) == 0) {
			arrays[0] = v->key;
		}
		v = v->left;
		i++;
	}

	for (i; i < stop; i++) {
		if (i == stop - 1) {
			arrays[0] = v->key;
		}

		if (v->left == nullptr) {
			v = v->right;
		}
		else if (v->right == nullptr) {
			v = v->left;
		}
		else {
			if (v->left->level < v->right->level) {
				v = v->right;
			}
			else {
				v = v->left;
			}
		}
	}
	arrays[1] = v->key;

	return arrays;
}

long long* walkTreeParentMedian(Tree* v, int stop) {
	long long* arrays = new long long[4];
	long long save = 0;
	int key1 = 0, key2 = 0;

	for (int i = 0; i < stop; i++) {
		if (i == stop - 1) {
			arrays[0] = v->key;
		}

		save = v->key;
		if (v->left == nullptr) {
			less--;
			extraLess--;
			v = v->right;
		}
		else if (v->right == nullptr) {
			more--;
			extraMore--;
			v = v->left;
		}
		else {
			if (v->left->level < v->right->level) {
				less--;
				extraLess--;
				v = v->right;
			}
			else {
				more--;
				extraMore--;
				v = v->left;
			}
		}

		if ((less == -1 || more == -1) && key1 != 1) {
			arrays[2] = save;
			key1 = 1;
		}
		if ((extraLess == -1 || extraMore == -1) && key2 != 1) {
			arrays[3] = save;
			key2 = 1;
		}
	}
	arrays[1] = v->key;

	return arrays;
}

long long searchMedian(Tree* v, int& check, Tree* first) {
	int countNode = 0;
	int dif = 0;

	if (v->left == nullptr && v->right == nullptr) {
		check = 1;
		return 0;
	}

	if (v->left == nullptr) {
		countNode = v->right->level + 2;
	}
	else if (v->right == nullptr) {
		countNode = v->left->level + 2;
	}
	else {
		countNode = v->left->level + 2 + v->right->level;

		if (countNode % 2 != 0) {
			less = more = extraLess = extraMore = (countNode - 1) / 2;
			dif = v->left->level - v->right->level;
			long long* arrayMedian = new long long[4];
			long long* arrays = new long long[2];


			if (dif > 0) {
				long long revers = 0;
				more -= v->right->level;
				extraMore = more - 1;
				arrayMedian = walkTreeParentMedian(v, v->left->level + 1);
				arrays = walkTreeParent(v, v->right->level + 1, dif);

				revers = arrayMedian[3];
				arrayMedian[3] = arrayMedian[2];
				arrayMedian[2] = revers;
			}
			else {
				less -= v->left->level + 1;
				extraLess = less + 1;
				arrayMedian = walkTreeParentMedian(v, v->right->level + 1);
				arrays = walkTreeParent(v, v->left->level + 1, dif);
			}

			long long sum01 = arrays[0] + arrayMedian[1];
			long long sum10 = arrays[1] + arrayMedian[0];

			long long minFirst = first->key + arrayMedian[1];
			if ((first->left == nullptr || first->right == nullptr) && first->sumChild == v->sumChild - 1 && minFirst <= sum01 && minFirst <= sum10) {
				
				less = more = (countNode - 1) / 2;
				arrayMedian[3] = walkTree(first);
				
				if (minFirst == sum01 || minFirst == sum10) {
					if (first->key < v->key) {
						return arrayMedian[3];
					}
				}
				else {
					return arrayMedian[3];
				}
			}

			if (sum01 == sum10) {
				if (arrayMedian[2] != arrayMedian[3]) {
					check = 1;
				}
				else {
					return arrayMedian[2];
				}
			}
			else if (sum01 > sum10) {
				return arrayMedian[2];
			}
			else {
				return arrayMedian[3];
			}


			countNode = 0;
		}
	}

	if (countNode % 2 != 0) {
		less = more = (countNode - 1) / 2;
		return walkTree(v);
	}

	check = 1;
	return 0;
}


void searchRoot(Tree* v, Tree** root) {
	if (v && pas != 0) {
		searchRoot(v->left, root);
		if (v->sumChild == maxRootKey && pas != 0) {
			*root = v;
			pas = 0;
		}
		searchRoot(v->right, root);
	}
}

void setLevel(Tree* v) {
	if (v) {
		setLevel(v->left);
		setLevel(v->right);


		if (v->left != nullptr && v->right != nullptr) {

			if (v->left->level > v->right->level) {
				v->level = v->left->level + 1;
			}
			else {
				v->level = v->right->level + 1;
			}

			v->sumChild = 2 + v->left->level + v->right->level;
		}
		else {
			if (v->left != nullptr) {
				v->level = v->left->level + 1;
			}
			else if (v->right != nullptr) {
				v->level = v->right->level + 1;
			}

			v->sumChild = v->level;
		}

		if (maxRootKey < v->sumChild) {
			maxRootKey = v->sumChild;
		}

	}
}

int main() {
	std::ifstream in("tst.in");
	std::ofstream out("tst.out");
	std::string line;

	BinTree tree;
	Tree* root = nullptr;
	Tree* first;
	int check = 0;
	long long result;



	while (std::getline(in, line)) {
		tree.inset(std::stoll(line));
		count++;
	}
	first = tree.getFirst();
	setLevel(first);

	if ((first->left == nullptr || first->right == nullptr) && first->sumChild == maxRootKey) {
		root = first;
	}
	else {
		searchRoot(first, &root);
	}

	result = searchMedian(root, check, first);
	if (check == 0) {
		tree.deleteElement(result);
	}
	show(first, out);

	delete first;
	out.close();
	in.close();
	return 0;
}