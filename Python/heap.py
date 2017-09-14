# Implementation of heap from list in Python

class Heap(object):

    def __init__(self):
        self.list = []
        self.last_index = -1

    def insert(self, x):
        self.last_index += 1
        if not self.list:
            self.list.append(x)
            return
        self.list.append(x)
        index = self.last_index
        parent = int((index-1)/2)
        while (self.list[index] > self.list[parent]) and parent >= 0:
            temp = self.list[index]
            self.list[index] = self.list[parent]
            self.list[parent] = temp
            index = parent
            parent = int((parent-1)/2)

    def max(self):
        return self.list[0]

    def pop(self):
        head = self.list[0]
        self.list[0] = self.list[self.last_index]
        self.list.pop()
        print self.list
        self.last_index -= 1
        index = 0
        left_child_index = (index * 2) + 1
        right_child_index = (index * 2) + 2
        if left_child_index > self.last_index: # 0 or 1 nodes in heap, done
            return head

        if right_child_index > self.last_index: # no right child
            right_child_index = index

        while (self.list[index] < self.list[right_child_index]) or \
              (self.list[index] < self.list[left_child_index]):
              if self.list[left_child_index] > self.list[right_child_index]:
                  temp = self.list[index]
                  self.list[index] = self.list[left_child_index]
                  self.list[left_child_index] = temp
                  index = left_child_index
                  left_child_index = (index * 2) + 1
                  right_child_index = (index * 2) + 2
              else:
                  temp = self.list[index]
                  self.list[index] = self.list[right_child_index]
                  self.list[right_child_index] = temp
                  index = right_child_index
                  left_child_index = (index * 2) + 1
                  right_child_index = (index * 2) + 2

              if left_child_index > self.last_index:
                  return head

              if right_child_index > self.last_index:
                  right_child_index = index

if __name__ == "__main__":
    h = Heap()
    for i in range(20):
        h.insert(i)
    print h.list
    print h.pop()
    print h.list
