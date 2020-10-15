#ifndef BST_H
#define BST_H

#include <string>
#include <sstream>
#include <iostream>

template <class T> class BST;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;

	Node<T>* succesor();

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	void add(T);
	bool find(T); //se manda a llamar en el add
	int whatlevelamI(T);
	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void levelorder(std::stringstream&) const;
	void printlevel(std::stringstream&, int) const;
  bool ancestors(T, std::stringstream&) const;
	int height() const;

	friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	}
	else if (val < value) {
		return (left != 0 && left->find(val));
	}
	else if (val > value) {
		return (right != 0 && right->find(val));
	}
	return false;
}

template <class T>
int Node<T>::whatlevelamI(T val) {
	if (val == value) {
		return 1;
	} else if (val < value) {
		if(left != 0)
			return left->whatlevelamI(val) + 1;
	} else if (val > value) {
		if (right != 0)
		return right->whatlevelamI(val) + 1;
	}
	return -1;
}


template <class T>
bool Node<T>::ancestors(T val, std::stringstream &aux) const{

	if (val == value) {
	  return true;
	}
	else if (val < value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (left != 0 && left->ancestors(val,aux));
	}
	else if (val > value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (right != 0 && right->ancestors(val,aux));
	}
	return false;
}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return ri;
	}

	if (left->right == 0) {
		left = left->left;
		le->left = 0;
		return le;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}



template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
	if (left != 0) {
		left->postorder(aux);
	}

	if (right != 0) {
		right->postorder(aux);
	}
	if (aux.tellp() != 1) {
			aux << " ";
	}
	aux << value;
}

template <class T>
void Node<T>::printlevel(std::stringstream &aux, int level) const {

	if(level == 0){
		if (aux.tellp() != 1) {
				aux << " ";
		}
		aux << value;
	}
	if (left != 0) {
		left->printlevel(aux, level -1);
	}
	if (right != 0) {
		right->printlevel(aux, level -1);
	}

}

template <class T>
void Node<T>::levelorder(std::stringstream &aux) const {
	int level = height();
	for(int i = 0; i < level; i++){
			printlevel(aux, i);
	}
	
}

template <class T>
int Node<T>::height() const {

	int level_left = 0;
	int level_right = 0;

	if (left != 0) {
		level_left = left->height() + 1;
	}
	if (right != 0) {
		level_right= right->height() +1;
	}
	if (level_left == 0 && level_right == 0)
		return 1;

	return (level_right > level_left) ? level_right : level_left;
}
//friend class
template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	int  whatlevelamI(T) const;
	std::string inorder() const; //visit
	std::string preorder() const;//visit
	std::string postorder() const;//visit
	std::string levelorder() const;//visit
	std::string visit();
	std::string ancestors(T) const;
	int height() const;
};

template <class T>
BST<T>::BST() : root(0) {}


template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}


template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	}
	else {
		return false;
	}
}

template <class T>
int BST<T>::whatlevelamI(T val) const {
	if (root != 0) {
	 	int num = root->whatlevelamI(val);
		if(num < 0) return -1;
		return num;
	}
	else {
		return -1;
	}
}

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::postorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::levelorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->levelorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::height() const {
	return root->height();
}


template <class T>
std::string BST<T>::ancestors(T val) const {
	std::stringstream aux;
	aux << "[";
	if (!empty()) {
		if(!root->ancestors(val, aux))
			return "[]";
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::visit() {
	std::stringstream aux;
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << levelorder();
	return aux.str();
}

#endif
