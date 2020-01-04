/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.ipp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:49:20 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/04 18:02:58 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

template<typename value_type>
Vector<value_type>::iterator::iterator():
	pointer(nullptr), position(0)
{
}

template<typename value_type>
Vector<value_type>::iterator::iterator(value_type *val, int position):
	pointer(val), position(position)
{
}

template<typename value_type>
Vector<value_type>::iterator::iterator(Vector<value_type>::iterator const &other):
	pointer(other.pointer), position(other.position)
{
}

template<typename value_type>
typename Vector<value_type>::iterator &Vector<value_type>::iterator::operator=(Vector<value_type>::iterator const &other)
{
	this->pointer = other.pointer;
	this->position = other.position;
	return (*this);
}

template<typename value_type>
Vector<value_type>::iterator::~iterator()
{
}

template<typename value_type>
value_type &Vector<value_type>::iterator::operator*()
{
	return (*(this->pointer + this->position));
}

template<typename value_type>
value_type const &Vector<value_type>::const_iterator::operator*() const
{
	return (*(this->pointer + this->position));
}

template<typename value_type>
bool Vector<value_type>::iterator::operator==(iterator const &other) const
{
	return (this->position == other.position);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator!=(iterator const &other) const
{
	return (this->position != other.position);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator<(iterator const &other) const
{
	return (this->position < other.position);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator<=(iterator const &other) const
{
	return (this->position <= other.position);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator>(iterator const &other) const
{
	return (this->position > other.position);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator>=(iterator const &other) const
{
	return (this->position >= other.position);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator++(int)
{
	++this->position;
	return (*this);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator++()
{

	Vector<value_type>::iterator tmp(*this);
	operator++();
	return (tmp);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator--(int)
{
	--this->position;
	return (*this);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator--()
{
	Vector<value_type>::iterator tmp(*this);
	operator--();
	return (tmp);
}

template<typename value_type>
Vector<value_type>::const_iterator::const_iterator():
	iterator(nullptr, 0)
{
}

template<typename value_type>
Vector<value_type>::const_iterator::const_iterator(value_type *val, int position):
	iterator(val, position)
{
}

template<typename value_type>
Vector<value_type>::const_iterator::const_iterator(Vector<value_type>::const_iterator const &other):
	iterator(other.pointer, other.position)
{
}

template<typename value_type>
typename Vector<value_type>::const_iterator &Vector<value_type>::const_iterator::operator=(Vector<value_type>::const_iterator const &other)
{
	this->pointer = other.pointer;
	this->position = other.position;
	return (*this);
}

template<typename value_type>
Vector<value_type>::const_iterator::~const_iterator()
{
}

template<typename value_type>
Vector<value_type>::reverse_iterator::reverse_iterator():
	iterator(nullptr, 0)
{
}

template<typename value_type>
Vector<value_type>::reverse_iterator::reverse_iterator(value_type *val, int position):
	iterator(val, position)
{
}

template<typename value_type>
Vector<value_type>::reverse_iterator::reverse_iterator(Vector<value_type>::reverse_iterator const &other):
	iterator(other.pointer, other.position)
{
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator &Vector<value_type>::reverse_iterator::operator=(Vector<value_type>::reverse_iterator const &other)
{
	this->pointer = other.pointer;
	this->position = other.position;
	return (*this);
}

template<typename value_type>
Vector<value_type>::reverse_iterator::~reverse_iterator()
{
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::reverse_iterator::operator++(int)
{
	--this->position;
	return (*this);
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::reverse_iterator::operator++()
{

	Vector<value_type>::reverse_iterator tmp(*this);
	operator--();
	return (tmp);
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::reverse_iterator::operator--(int)
{
	++this->position;
	return (*this);
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::reverse_iterator::operator--()
{
	Vector<value_type>::reverse_iterator tmp(*this);
	operator++();
	return (tmp);
}


template<typename value_type>
Vector<value_type>::const_reverse_iterator::const_reverse_iterator():
	const_iterator(nullptr, 0), reverse_iterator(nullptr, 0)
{
}

template<typename value_type>
Vector<value_type>::const_reverse_iterator::const_reverse_iterator(value_type *val, int position):
	const_iterator(val, position), reverse_iterator(val, position)
{
}

template<typename value_type>
Vector<value_type>::const_reverse_iterator::const_reverse_iterator(Vector<value_type>::const_reverse_iterator const &other):
	const_iterator(other.pointer, other.position), reverse_iterator(other.pointer, other.position)
{
}

template<typename value_type>
typename Vector<value_type>::const_reverse_iterator &Vector<value_type>::const_reverse_iterator::operator=(Vector<value_type>::const_reverse_iterator const &other)
{
	this->pointer = other.pointer;
	this->position = other.position;
	return (*this);
}

template<typename value_type>
Vector<value_type>::const_reverse_iterator::~const_reverse_iterator()
{
}

template<typename value_type>
Vector<value_type>::Vector():
	capacity_(128), size_(0), container(nullptr)
{
	this->container = new value_type[128]();
}

template<typename value_type>
Vector<value_type>::Vector(Vector<value_type>::iterator first, Vector<value_type>::iterator last):
	capacity_(0), size_(0), container(nullptr)
{
	this->container = nullptr;
	this->assign(first, last);
}

template<typename value_type>
Vector<value_type>::Vector(size_t n, value_type const &val):
	capacity_(0), size_(0), container(nullptr)
{
	this->container = nullptr;
	this->resize(n, val);
}

template<typename value_type>
Vector<value_type>::Vector(Vector<value_type> const &other):
	capacity_(0), size_(0), container(nullptr)
{
	this->container = nullptr;
	this->reserve(other.capacity_);
	this->assign(other.begin(), other.end());
}

template<typename value_type>
Vector<value_type>::~Vector()
{
	delete[] this->container;
	this->size_ = 0;
}

template<typename value_type>
Vector<value_type> &Vector<value_type>::operator=(Vector<value_type> const &other)
{
	this->clear();
	this->assign(other.begin(), other.end());
}


template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin(void)
{
	return (Vector<value_type>::iterator(&this->front(), 0));
}

template<typename value_type>
typename Vector<value_type>::const_iterator Vector<value_type>::begin(void) const
{
	return (Vector<value_type>::const_iterator(&this->front(), 0));
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::rbegin(void)
{
	return (Vector<value_type>::reverse_iterator(&this->front(), this->size_ - 1));
}

template<typename value_type>
typename Vector<value_type>::const_reverse_iterator Vector<value_type>::rbegin(void) const
{
	return (Vector<value_type>::const_reverse_iterator(&this->front(), this->size_ - 1));
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::end(void)
{
	return (Vector<value_type>::iterator(&this->front(), this->size_));
}

template<typename value_type>
typename Vector<value_type>::const_iterator Vector<value_type>::end(void) const
{
	return (Vector<value_type>::const_iterator(&this->front(), this->size_));
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::rend(void)
{
	return (Vector<value_type>::reverse_iterator(&this->front(), -1));
}

template<typename value_type>
typename Vector<value_type>::const_reverse_iterator Vector<value_type>::rend(void) const
{
	return (Vector<value_type>::const_reverse_iterator(&this->front(), -1));
}

template<typename value_type>
size_t Vector<value_type>::size(void) const
{
	return (this->size_);
}

template<typename value_type>
size_t Vector<value_type>::max_size(void) const
{
	return (this->size_type * 1000000); // TODO: ???
}

template<typename value_type>
void Vector<value_type>::resize(size_t size, value_type val)
{
	if (size > this->capacity_)
		this->resize(size);
	if (size > this->size_)
	{
		for (size_t i = this->size_; i < size; i++)
			this->container[i] = val;
		this->size_ = size;
	}
	else if (size < this->size_)
	{
		for (size_t i = size; i < this->size_; i++)
			delete this->container[i];
		this->size_ = size;
	}
}

template<typename value_type>
size_t Vector<value_type>::capacity(void) const
{
	return (this->capacity_);
}

template<typename value_type>
bool Vector<value_type>::empty(void) const
{
	return (this->size_ == 0);
}

template<typename value_type>
void Vector<value_type>::reserve(size_t size)
{
	if (size > this->capacity_)
	{
		value_type *tmp = new value_type[size]();
		for (size_t i = 0; i < this->size_; i++)
			tmp[i] = this->container[i];
		delete[] this->container;
		this->container = tmp;
		this->capacity_ = size;
	}
}


template<typename value_type>
value_type &Vector<value_type>::operator[](size_t idx)
{
	return (this->at(idx));
}

template<typename value_type>
value_type const &Vector<value_type>::operator[](size_t idx) const
{
	return (this->at(idx));
}

template<typename value_type>
value_type &Vector<value_type>::at(size_t idx)
{
	assert(idx < this->size_);
	return (this->container[idx]);
}

template<typename value_type>
value_type const &Vector<value_type>::at(size_t idx) const
{
	assert(idx < this->size_);
	return (this->container[idx]);
}

template<typename value_type>
value_type &Vector<value_type>::front(void)
{
	return (this->container[0]);
}

template<typename value_type>
value_type const &Vector<value_type>::front(void) const
{
	return (this->container[0]);
}

template<typename value_type>
value_type &Vector<value_type>::back(void)
{
	return (this->container[this->size_ - 1]);
}

template<typename value_type>
value_type const &Vector<value_type>::back(void) const
{
	return (this->container[this->size_ - 1]);
}

template<typename value_type>
void Vector<value_type>::assign(Vector<value_type>::iterator first, Vector<value_type>::iterator last)
{
	size_t size = last - first;
	this->clear();
	if (size > this->capacity_)
		this->reserve(size);
	while (first != last)
		this->container.push_back(*first++);
	this->size_ = size;
}

template<typename value_type>
void Vector<value_type>::assign(size_t size, value_type const &val)
{
	this->clear();
	if (size > this->capacity_)
		this->reserve(size);
	for (size_t i = 0; i < size; i++)
		this->container[i] = val;
	this->size_ = size;
}

template<typename value_type>
void Vector<value_type>::push_back(value_type const &val)
{
	if (this->size_ == this->capacity_)
		this->reserve(this->capacity_ + 256);
	this->container[this->size_++] = val;
}

template<typename value_type>
void Vector<value_type>::pop_back(void)
{
	this->size_--;
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::insert(Vector<value_type>::iterator position, value_type const &val)
{
	this->insert(position, 1, val);
}

template<typename value_type>
void Vector<value_type>::insert(Vector<value_type>::iterator position, size_t size, value_type const &val)
{
	if (this->size_ + size == this->capacity_)
		this->reserve(this->capacity_ + size + 256);
	for (size_t i = 0; i < this->size_; i++)
	{
		if (&this->container[i] == &*position)
		{
			for (size_t j = this->size_; j >= 1 && j >= i; j--)
				this->container[j + size - 1] = this->container[j - 1];
			for (size_t j = 0; j < size; j++)
				this->container[i + j] = val;
			this->size_ += size;
			break ;
		}
	}
}

template<typename value_type>
void Vector<value_type>::insert(Vector<value_type>::iterator position, Vector::iterator first, Vector::iterator last)
{
	size_t size = last - first;
	if (this->size_ + size == this->capacity_)
		this->reserve(this->capacity_ + size + 256);
	for (size_t i = 0; i < this->size_; i++)
	{
		if (this->container[i] == position)
		{
			for (size_t j = this->size_ - 1; j > i + 1; j++)
				this->container[j + size] = this->container[j - 1];
			for (size_t j = 0; j < size; j++)
				this->container[i + j] == *first++;
			this->size_ += size;
			break ;
		}
	}
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::erase(Vector<value_type>::iterator position)
{
	this->erase(position, position + 1);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::erase(Vector::iterator first, Vector::iterator last)
{
	for (size_t i = 0; i < this->size_; i++)
	{
		if (this->container[i] == first)
		{
			size_t pos_stop = i + 1;
			for (size_t j = i + 1; j < this->size_; j++)
			{
				if (this->container[j] == last)
					break;
				this->container[j] = value_type();
				pos_stop++;
			}
			for ( ; pos_stop < this->size_; pos_stop++)
			{
				this->container[i++] = this->container[pos_stop];
				this->size_--;
			}
			break ;
		}
	}
}

template<typename value_type>
void Vector<value_type>::swap(Vector<value_type> &other)
{
	(void)other;
	// TODO:
}

template<typename value_type>
void Vector<value_type>::clear(void)
{
	for (size_t i = 0; i < this->size_; i++)
		this->container[i] = value_type();
	this->size_ = 0;
}

}