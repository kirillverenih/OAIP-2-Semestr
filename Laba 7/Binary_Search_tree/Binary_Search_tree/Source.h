
#include "pch.h"
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <map>
using namespace std;
class binary_tree
{
public:


	binary_tree()
	{
		this->amount_of_nodes = 0;
	};
	class node
	{
	public:
		int key;
		string FIO;
		int passport_num;
		node *left_ptr = nullptr;
		node *right_ptr = nullptr;

		node() {};

		node(int key , string FIO , int passport_num)
		{

			this->key = key;
			this->FIO = FIO;
			this->passport_num = passport_num;

		};

		friend ostream& operator<< (std::ostream &out , const node &nodic)
		{
			if (nodic.FIO != "ERROR - NO SUCH NODE IN THE TREE")
			{
				out << "Node key: " << nodic.key << " | " << "Node FIO: " <<
					nodic.FIO << " | " << "Node passport: " << nodic.passport_num
					<< " | " << "Node adress: " << &nodic;
				return out;
			}
			else
			{
				out << "No such a node in a tree" << endl;
				return out;
			};
		};

		node& operator=(const node &a)
		{
			FIO = a.FIO;
			passport_num = a.passport_num;
			key = a.key;
			left_ptr = a.left_ptr;
			right_ptr = a.right_ptr;
			return *this;
		}
	};
	node* for_errors = new node(0 , "ERROR - NO SUCH NODE IN THE TREE" , 0);

	void _print_back(node *nodic)
	{
		if (nodic != nullptr)
		{
			_print_back(nodic->left_ptr);
			cout << *nodic << endl;
			_print_back(nodic->right_ptr);
		}
	}

	void _going_through(node *nodic , vector <node> &a)
	{//Принимает указатель записывыет в вектор обьектов
		if (nodic != nullptr)
		{
			_going_through(nodic->left_ptr , a);
			a.push_back(*nodic);
			_going_through(nodic->right_ptr , a);
		}
	};

	void _going_through(node &nodic , vector <node*> &a)
	{//Принимает сам обьект записывает в вектор указателей
		if (&nodic != nullptr)
		{
			_going_through(*nodic.left_ptr , a);
			a.push_back(&nodic);
			_going_through(*nodic.right_ptr , a);
		}
	};

	void print_back()
	{
		_print_back(root);
	};

	void clear()
	{
		vector <node*> tmp;
		_going_through(*this->root , tmp);
		/*cout << "------CLEANING START------" << endl << endl;*/
		for (size_t i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == this->root)
			{
				/*cout << "DELETING: " << tmp[i] << " (root)"<< endl;*/
				delete this->root;
				this->root = nullptr;
				amount_of_nodes--;
			}
			else
			{
				/*cout << "DELETING: " << tmp[i] << endl;*/
				delete tmp[i];
				amount_of_nodes--;
			}
		}
		/*cout << endl<< "---------CLEANED----------" << endl << endl;*/

	}

	void _quicksort(vector <node> &a , int left , int right)
	{
		int i = left , j = right;
		node temp;
		int devidednum = a[(left + right) / 2].key;
		/* partition */
		while (i <= j)
		{
			while (a[i].key < devidednum)
				i++;
			while (a[j].key > devidednum)
				j--;
			if (i <= j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i++;
				j--;
			}
		};
		if (left < j)
			_quicksort(a , left , j);
		if (i < right)
			_quicksort(a , i , right);
	};

	void rebalance()
	{
		vector <node> temp;
		node *rootic = this->root;
		_going_through(rootic , temp);
		_quicksort(temp , 0 , temp.size() - 1);
		this->clear();
		random_shuffle(temp.begin() , temp.end());
		for (int i = 0; i < temp.size(); i++)
		{
			this->add(temp[i].key , temp[i].FIO , temp[i].passport_num);
		}

	};


	node* _find_node(int key , node *begin)
	{
		if (begin->key == key)
		{
			return begin;
		}
		else
		{
			if (key > begin->key)
			{
				if (begin->right_ptr != nullptr)
				{
					return _find_node(key , begin->right_ptr);
				}
				else
				{
					return nullptr;
				}
			}
			else
			{
				if (begin->left_ptr != nullptr)
				{
					return _find_node(key , begin->left_ptr);
				}
				else
				{
					return nullptr;
				}
			}
		}
	};

	node find(int key)
	{
		if (!(this->contains(key)))
		{
			return *for_errors;
		}
		else
		{
			return (*(_find_node(key , this->root)));
		}
	}



	bool contains(int key)
	{
		return bool(_find_node(key , this->root));
	};

	node* _find_place(int key , node *begin)
	{
		if (key < begin->key)
		{
			if (begin->left_ptr != nullptr)
			{
				return _find_place(key , begin->left_ptr);
			}
			else
			{
				return begin;
			}
		}
		else
		{
			if (begin->right_ptr != nullptr)
			{
				return _find_place(key , begin->right_ptr);
			}
			else
			{
				return begin;
			}
		}



	};

	void remove(int key)
	{
		if (this->root->key == key)
		{
			vector <node> temp;
			node rootic = *this->root;
			_going_through(this->root , temp);
			_quicksort(temp , 0 , temp.size() - 1);
			this->clear();
			for (size_t i = 0; i < temp.size(); i++)
			{
				if (temp[i].key == rootic.key)
				{
					temp.erase(temp.begin() + i);
				}
			}
			random_shuffle(temp.begin() , temp.end());
			for (int i = 0; i < temp.size(); i++)
			{
				this->add(temp[i].key , temp[i].FIO , temp[i].passport_num);
			}

		}
		else
		{
			if (this->contains(key))
			{
				vector <node*> temp;
				_going_through(*this->root , temp);
				int i = 0;
				while (temp[i]->key != key)
				{
					i++;
				};
				int choise;
				if (temp[i]->left_ptr == nullptr && temp[i]->right_ptr == nullptr)
				{
					choise = 0;
				}
				if (temp[i]->left_ptr != nullptr && temp[i]->right_ptr == nullptr)
				{
					choise = 1;
				}
				if (temp[i]->left_ptr == nullptr && temp[i]->right_ptr != nullptr)
				{
					choise = 2;
				}
				if (temp[i]->left_ptr != nullptr && temp[i]->right_ptr != nullptr)
				{
					choise = 3;
				}
				switch (choise)
				{
				case 0:
				{
					int j = 0;
					for (j; j < temp.size(); j++)
					{
						if (temp[j]->left_ptr == temp[i] || temp[j]->right_ptr == temp[i])
						{
							break;
						}
					}
					if (temp[j]->right_ptr == temp[i])
					{
						temp[j]->right_ptr = nullptr;
					}
					if (temp[j]->left_ptr == temp[i])
					{
						temp[j]->left_ptr = nullptr;
					}
					delete temp[i];
					amount_of_nodes--;
					break;
				};
				case 1:
				{
					int j = 0;
					for (j; j < temp.size(); j++)
					{
						if (temp[j]->left_ptr == temp[i] || temp[j]->right_ptr == temp[i])
						{//PROBLEM
							break;
						}
					}
					if (temp[j]->right_ptr == temp[i])
					{
						temp[j]->right_ptr = temp[i]->left_ptr;
					}
					if (temp[j]->left_ptr == temp[i])
					{
						temp[j]->left_ptr = temp[i]->left_ptr;
					}
					delete temp[i];
					amount_of_nodes--;
					break;

				};
				case 2:
				{
					int j = 0;
					for (j; j < temp.size(); j++)
					{
						if (temp[j]->left_ptr == temp[i] || temp[j]->right_ptr == temp[i])
						{
							break;
						}
					}
					if (temp[j]->right_ptr == temp[i])
					{
						temp[j]->right_ptr = temp[i]->right_ptr;
					}
					if (temp[j]->left_ptr == temp[i])
					{
						temp[j]->left_ptr = temp[i]->right_ptr;
					}
					delete temp[i];
					amount_of_nodes--;
					break;
				};
				case 3:
				{
					int j = 0;
					for (j; j < temp.size(); j++)
					{
						if (temp[j]->left_ptr == temp[i] || temp[j]->right_ptr == temp[i])
						{
							break;
						}
					}
					node* to_which_append = temp[i]->right_ptr;
					node* which_to_append = temp[i]->left_ptr;
					while (to_which_append->left_ptr != nullptr)
					{
						to_which_append = to_which_append->left_ptr;
					}
					if (temp[j]->right_ptr == temp[i])
					{
						temp[j]->right_ptr = temp[i]->right_ptr;
					}
					if (temp[j]->left_ptr == temp[i])
					{
						temp[j]->left_ptr = temp[i]->right_ptr;
					}
					to_which_append->left_ptr = which_to_append;
					delete temp[i];
					amount_of_nodes--;
					this->rebalance();
					break;
				};
				}

			}
			else
			{
				return;
			}
		}
	};

	void _print_straight(node* a , int count)
	{
		if (a == nullptr)
			return;
		for (int i = 0; i < count; ++i)
			cout << "|";
		cout << *a << endl;
		count--;
		_print_straight(a->left_ptr , count);//С помощью рекурсивного посещаем левое поддерево
		_print_straight(a->right_ptr , ++count); //С помощью рекурсии посещаем правое поддерево
	};

	void print_straight()
	{
		_print_straight(this->root , this->amount_of_nodes);
	};

	void _count(node* tree , map<int , int>&m , int level)
	{
		m[level]++;
		if (tree->left_ptr)  _count(tree->left_ptr , m , level + 1);
		if (tree->right_ptr) _count(tree->right_ptr , m , level + 1);
	}

	void count()
	{
		map<int , int> m;
		_count(this->root , m , 0);
		for (auto var : m)
		{
			cout << "On " << var.first << " level" << " there is(are) " << var.second << " node(s) " << endl;
		}
	}

	void add(int key , string FIO , int passport_num)
	{
		if (amount_of_nodes == 0)
		{
			this->root = new node(key , FIO , passport_num);
			amount_of_nodes++;
		}
		else
		{
			if (!this->contains(key))
			{
				node *to_add = new node(key , FIO , passport_num);
				node *temp = _find_place(key , this->root);
				if (key > temp->key)
				{
					temp->right_ptr = to_add;
				}
				else
				{
					temp->left_ptr = to_add;
				}
				amount_of_nodes++;
			}
		}

	};
	int amount_of_nodes;
	node *root = nullptr;
};