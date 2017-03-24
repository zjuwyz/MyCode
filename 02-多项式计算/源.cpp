#include <iostream>
using namespace std;

struct term
{
	int con;//系数
	int exp;//指数
	term *next;

	term()
	{
		exp = 0;
		con = 0;
		next = NULL;
	}

	~term()
	{
		delete next;
	}
};

class Polynome
{
	term *head;
public:
	Polynome()
	{
		head = new term;
	}

	Polynome(const Polynome &a);

	~Polynome()
	{
		delete head;
		head = NULL;
	}

	Polynome operator +(const Polynome &p) const;
	Polynome operator *(const term &b) const;
	Polynome operator *(const Polynome &p) const;
	Polynome operator =(const Polynome &a);
	friend istream& operator >>(istream &in, Polynome &p);
	friend ostream& operator <<(ostream &out, Polynome p);
};

Polynome::Polynome(const Polynome &a)
{
	head = new term;
	term *p = head;
	term *q = a.head;
	while (q->next != NULL)
	{
		p = p->next = new term;
		q = q->next;
		p->con = q->con;
		p->exp = q->exp;
	}
}

Polynome Polynome::operator+(const Polynome &p) const
{
	Polynome ret;

	term *a = this->head;
	term *b = p.head;
	term *ans = ret.head;

	a = a->next;
	b = b->next;

	while (a != NULL && b != NULL)
	{
		if (a->exp > b->exp)
		{
			ans = ans->next = new term;
			ans->exp = a->exp;
			ans->con = a->con;
			a = a->next;
			continue;
		}
		if (a->exp == b->exp)
		{
			if (a->con + b->con != 0)
			{
				ans = ans->next = new term;
				ans->con = a->con + b->con;
				ans->exp = a->exp;
			}

			a = a->next;
			b = b->next;
			continue;
		}
		if (a->exp < b->exp)
		{
			ans = ans->next = new term;
			ans->exp = b->exp;
			ans->con = b->con;
			b = b->next;
			continue;
		}
	}

	if (b != NULL)
	{
		a = b;
	}

	while (a != NULL)
	{
		ans = ans->next = new term;
		*ans = *a;
		a = a->next;
	}

	return ret;
}

Polynome Polynome::operator*(const term &b) const
{
	Polynome ret;
	term *a = this->head;
	term *ans = ret.head;

	while (a->next != NULL)
	{
		a = a->next;
		ans = ans->next = new term;

		ans->exp = a->exp + b.exp;
		ans->con = a->con * b.con;
	}
	return ret;
}

Polynome Polynome::operator*(const Polynome &p) const
{
	Polynome ret;
	term *b = p.head;
	while (b->next != NULL)
	{
		b = b->next;
		ret = ret + *this * *b;
	}

	return ret;
}

Polynome Polynome::operator=(const Polynome &a)
{
	delete head;
	head = new term;
	term *p = head;
	term *q = a.head;
	while (q->next != NULL)
	{
		p = p->next = new term;
		q = q->next;
		p->con = q->con;
		p->exp = q->exp;
	}
	return *this;
}

istream& operator>>(istream &in, Polynome &p)
{
	int n;
	in >> n;
	term *now = p.head;
	for (int i = 0; i < n; i++)
	{
		if (now->next == NULL)
		{
			now = now->next = new term;
		}
		else
		{
			now = now->next;
		}
		int con;
		int exp;
		in >> con >> exp;
		now->con = con;
		now->exp = exp;
	}

	return in;
}

ostream& operator<<(ostream &out, Polynome p)
{
	if (p.head->next == NULL)
	{
		out << "0 0";
	}
	else
	{
		term *now = p.head;
		while (now->next != NULL)
		{
			now = now->next;
			out << now->con << " " << now->exp;
			if (now->next != NULL)
			{
				out << " ";
			}
		}
	}
	return out;
}

int main()
{
	Polynome a;
	Polynome b;
	cin >> a >> b;
	cout << a * b << endl << a + b;
	return 0;
}
