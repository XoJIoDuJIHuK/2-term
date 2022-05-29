//#include "stdafx.h"
#include "Tree.h"
namespace btree      // �������� ������, �� ����������� ������������ ������
{
	Object create(CMP(*f)(void*, void*))
	{
		return *(new Object(f));
	}
	//-------------------------------
	Node* Node::min()
	{
		Node* rc = this;
		if (rc->left != NULL)
			rc = rc->left->min();
		return rc;
	}
	//-------------------------------
	Node* Node::next()
	{
		Node* rc = this, * x = this;
		if (rc->right != NULL)
			rc = rc->right->min();
		else
		{
			rc = this->parent;
			while (rc != NULL && x == rc->right)
			{
				x = rc;
				rc = rc->parent;
			}
		}  return rc;
	}
	//-------------------------------
	void Node::scanDown(void(*f)(void* n))
	{
		f(this->data);
		std::cout << std::endl;
		if (this->left != NULL)
			this->left->scanDown(f);
		if (this->right != NULL)
			this->right->scanDown(f);
	}
	//-------------------------------
	Node* Object::search(void* d, Node* n)
	{
		Node* rc = n;
		if (rc != NULL)
		{
			if (isLess(d, n->data))
				rc = search(d, n->left);
			else
				if (isGreat(d, n->data))
					rc = search(d, n->right);
		} return rc;
	}
	//-------------------------------
	bool Object::insert(void* d)
	{
		Node* x = this->Root, * n = NULL;
		bool rc = true;
		while (rc == true && x != NULL)
		{
			n = x;
			if (isLess(d, x->data))
				x = x->left;          //����� ���� ���� - ����� ��� ������
			else
				if (isGreat(d, x->data))
					x = x->right;
				else
					rc = false;
		}
		if (rc == true && n == NULL)
			this->Root = new  Node(NULL, NULL, NULL, d);
		else
			if (rc == true && isLess(d, n->data))
				n->left = new  Node(n, NULL, NULL, d);
			else
				if (rc == true && isGreat(d, n->data))
					n->right = new  Node(n, NULL, NULL, d);
		return rc;
	};
	//-------------------------------
	bool  Object::deleteByNode(Node* n)
	{
		bool rc = true;
		if (rc = (n != NULL))
		{
			if (n->left == NULL && n->right == NULL)       //���� �������� ���
			{
				if (n->parent == NULL)
					this->Root = NULL;   //��������� �����
				else
					if (n->parent->left == n)
						n->parent->left = NULL;
					else
						n->parent->right = NULL;
				delete n;
			}
			else
				if (n->left == NULL && n->right != NULL) //������ ������ �������
				{
					if (n->parent == NULL)
						this->Root = n->right;
					else
						if (n->parent->left == n)
							n->parent->left = n->right;
						else
							n->parent->right = n->right;
					n->right->parent = n->parent;
					delete n;
				}
				else
					if (n->left != NULL && n->right == NULL) //������ ����� �������
					{
						if (n->parent == NULL)
							this->Root = n->left;
						else
							if (n->parent->right == n)
								n->parent->left = n->left;
							else
								n->parent->right = n->left;
						n->left->parent = n->parent;
						delete n;
					}
					else                                  //���� ���� ��� �������
						if (n->left != NULL && n->right != NULL) {
							Node* x = n->next();
							n->data = x->data;
							rc = deleteByNode(x);
						}
		} return  rc;
	}
	//-------------------------------
	void Node::scanLevel(void(*f)(void* n), int i)  //������� ������� ������
	{
		if (this->left != NULL)
			this->left->scanLevel(f, i);
		if (this->getLevel() == i)
			f(this->data);
		if (this->right != NULL)
			this->right->scanLevel(f, i);
	}
	//-------------------------------
	int Node::getLevel()
	{
		Node* rc = this;
		int q = 0;
		while (rc->parent != NULL)
		{
			rc = rc->parent;
			q++;
		}
		return q;
	}
	//-------------------------------
	void Node::scanByLevel(void(*f)(void* n))
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << '\t';
			this->scanLevel(f, i);
			std::cout << '\n';
		}
	}
	//-------------------------------
	void walkthrough_r_le_ri(Node* t)
	{
		if (t)
		{
			std::cout << t->data << std::endl;
			if (t->left)
			{
				walkthrough_r_le_ri(t->left);
			}
			if (t->right)
			{
				walkthrough_r_le_ri(t->right);
			}
		}
	}
	//-------------------------------
	void walkthrough_le_r_ri(Node* t)
	{
		if (t)
		{
			if (t->left)
			{
				walkthrough_r_le_ri(t->left);
			}
			std::cout << t->data << std::endl;
			if (t->right)
			{
				walkthrough_r_le_ri(t->right);
			}
		}
	}
	//-------------------------------
	void walkthrough_le_ri_r(Node* t)
	{
		if (t)
		{
			if (t->left)
			{
				walkthrough_r_le_ri(t->left);
			}
			if (t->right)
			{
				walkthrough_r_le_ri(t->right);
			}
			std::cout << t->data << std::endl;
		}
	}
	//------------------------------
	int Depth(Node* t)
	{
		if (t != NULL)
		{
			int A = Depth(t->left);
			int B = Depth(t->right);
			if (A > B) return A + 1;
			else return B + 1;
		}
		else return 0;
	}
	bool balance(Node* t)
	{
		int l, r;
		if (t == NULL) return true;
		else
		{
			if (balance(t->left) && balance(t->right))
			{
				l = Depth(t->left);
				r = Depth(t->right);
				if (l - r == 1 || r - l == 1 || l == r)
					return true;
				else
					return false;
			}
			else
				return false;
		}
	}
	//------------------------------
	void number_of_nodes(Node* t, int* i)
	{
		if (t)
		{
			(*i)++;
			if (t->right)
			{
				number_of_nodes(t->right, i);
			}
			if (t->left)
			{
				number_of_nodes(t->left, i);
			}
		}
	}
}

