#!/usr/bin/python
# -*- coding: UTF-8 -*-
import random
import math
import time

#得到一组随机数
def get_rand(n,m):
	i=0
	a=[]
	while i<m:
		a.append(random.randint(0,n))
		i+=1
	return a

#随机找一个基数
def sub_sort(array,low,high):
	key = array[low]
	while low < high:
		while low < high and array[high] >= key:
			high -= 1
		while low < high and array[high] < key:
			array[low] = array[high]
			low += 1
			array[high] = array[low]
	array[low] = key
	return low
#快速排序的实现
def quick_sort(array,low,high):
	if low < high:
		i = sub_sort(array,low,high)
		quick_sort(array,low,i)
		quick_sort(array,i+1,high)

	return array



#冒泡排序
def bubble_sort(arr):
	for i in range(len(arr))[::-1]:#i从大到小
		for j in range(i):
			if arr[j]>arr[j+1]:
				arr[j],arr[j+1] = arr[j+1],arr[j]

	return arr#返回排序后的数组

#实现插入排序
def insert_sort(arr):
	count = len(arr)
	for i in range(1, count):
		key = arr[i]
		j = i - 1
		while j >= 0:
			if arr[j] > key:
				arr[j + 1] = arr[j]
 				arr[j] = key
			j -= 1
	return arr




#冒泡
def bubble_sort1(arr):
	i=0
	while i<len(arr):
		j=0#j记得每次进入循环归0
		while j<(len(arr)-i-1) :
			if arr[j]>arr[j+1] :
				arr[j],arr[j+1]=arr[j+1],arr[j]
			j+=1
		i+=1
	return arr
#实现选择排序
def choice_sort(arr):
	for i in range(0, len (arr)):
		min = i
		for j in range(i + 1, len(arr)):
			if arr[j] < arr[min]:
				min = j
		arr[i], arr[min] = arr[min], arr[i]  
	return arr

#希尔排序
def shell_sort(items):

	inc = len(items) / 2
	while inc:
		for i in xrange(len(items)):
			j = i
			temp = items[i]
			while j >= inc and items[j-inc] > temp:
				items[j] = items[j - inc]
				j -= inc
			items[j] = temp
		inc = inc/2 if inc/2 else (0 if inc==1 else 1)
	return items



# 调整堆
def adjust_heap(lists, i, size):
	lchild = 2 * i + 1
	rchild = 2 * i + 2
	max = i
	if i < size / 2:
		if lchild < size and lists[lchild] > lists[max]:
			max = lchild
		if rchild < size and lists[rchild] > lists[max]:
 			max = rchild
		if max != i:
			lists[max], lists[i] = lists[i], lists[max]
			adjust_heap(lists, max, size)
 
# 创建堆
def build_heap(lists, size):
	for i in range(0, (size/2))[::-1]:
		adjust_heap(lists, i, size)
 
# 堆排序
def heap_sort(lists):
	size = len(lists)
	build_heap(lists, size)
	for i in range(0, size)[::-1]:
		lists[0], lists[i] = lists[i], lists[0]
		adjust_heap(lists, 0, i)
	return lists
#归并排序
def merge(left, right):
	i, j = 0, 0
	result = []
	while i < len(left) and j < len(right):
		if left[i] <= right[j]:
			result.append(left[i])
			i += 1
		else:
			result.append(right[j])
			j += 1
	result += left[i:]
	result += right[j:]
	return result
 
# 归并排序
def merge_sort(lists):
	if len(lists) <= 1:
		return lists
	num = len(lists) / 2
	left = merge_sort(lists[:num])
	right = merge_sort(lists[num:])
	return merge(left, right)

#基数排序
def radix_sort(lists, radix=10):
	k = int(math.ceil(math.log(max(lists), radix)))
	bucket = [[] for i in range(radix)]
	for i in range(1, k+1):
		for j in lists:
			bucket[j/(radix**(i-1)) % (radix**i)].append(j)
		del lists[:]
		for z in bucket:
			lists += z
			del z[:]
	return lists

def GetNowTime():

    return time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(time.time()))

#主程序
qw=raw_input("please input a random number max:")
wq=raw_input("please input How many numbers:")
c=get_rand(int(qw),int(wq))
f=open("result","w")
print "start sort time is:%s" % GetNowTime()
f.write(str(bubble_sort(c)))
print "end sort time is:%s" % GetNowTime()
f.close()
print "sort after is:plese see file_name:result"
while 1:
	i=0
	if c[i]>c[i+1] :
		print "sort wrong!"
	else :
		break		
