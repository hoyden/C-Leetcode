class MyCircularQueue(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        :type k: int
        """
        self.data = [0]*k
        self.head = -1
        self.tail = -1
        self.length = k
        

    def enQueue(self, value):
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        elif self.isEmpty():
            self.head = 0
        
        self.tail = (self.tail + 1) % self.length
        self.data[self.tail] = value
        return True
        

    def deQueue(self):
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
        if self.head == self.tail:
            self.head = -1
            self.tail = -1
            return True
        self.head = (self.head + 1) % self.length
        return True

    def Front(self):
        """
        Get the front item from the queue.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        return self.data[self.head]

    def Rear(self):
        """
        Get the last item from the queue.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        return self.data[self.tail]

    def isEmpty(self):
        """
        Checks whether the circular queue is empty or not.
        :rtype: bool
        """
        return self.head == -1
        

    def isFull(self):
        """
        Checks whether the circular queue is full or not.
        :rtype: bool
        """
        return (self.tail + 1) % self.length == self.head

if __name__ == "__main__":
    obj = MyCircularQueue(3)

        

