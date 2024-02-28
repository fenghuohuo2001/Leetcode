"""
@Name: 3.静态链表.py
@Auth: Huohuo
@Date: 2023/3/23-20:59
@Desc: 
@Ver : 
code_idea

静态链表通过索引、游标实现单向链表结构

python实现单链表 采用list结构存储

code from：
https://blog.csdn.net/weixin_43955170/article/details/118629058?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167957636516800188593536%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167957636516800188593536&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-118629058-null-null.142^v76^insert_down2,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=python%E9%9D%99%E6%80%81%E9%93%BE%E8%A1%A8&spm=1018.2226.3001.4187
"""

class Node:
    def __init__(self, next, val=None):
        self.val = val      # data
        self.next = next

class SLinkList:
    # give the length of list || define the list
    def __init__(self, size=7):
        self.size = size    #　the length of list
        self.link = [Node((i + 1) % self.size) for i in range(self.size)]   # define the list
        '''
        the follow code plays the same role as the above code
        #------------------------------------------------------#
        for i in range(self.size):
            self.link = Node((i + 1) % self.size)
        #------------------------------------------------------#
        
        #-------------------#iter process#---------------------#
        i = 0 : self.link = Node(1 % 7) = Node(1) -> next = 1
        i = 1 : self.link = Node(2 % 7) = Node(2) -> next = 2
        ······················
        i = 6 : self.link = Node(7 % 7) = Node(0) -> next = 0
        #------------------------------------------------------#
        '''
    # clear the list
    def clearSLL(self):
        self.__init__()     # do the init again

    # judge the list whether is empty or not
    def isEmpty(self):
        return False if self.link[self.size - 1].next else True
    '''
    #-------------------#iter process#---------------------#
    self.size = 7
    link[self.size - 1] = link[6]
    if the list is not empty:
        link[6].next = 0 
        return False
    if the list is empty:
        link[6].next != 0  (it should be the index+1) 
        return True
    '''

    # find the empty index
    def findEmpty(self):
        index = self.size
        for i in range(1, self.size - 1):
            if self.link[i].val is None:
                index = i
                break
        return index
    '''
    this def only can find one empty index
    if want to find more use the next one def 
    '''
    # find more empty index
    def findmoreEmpty(self):
        ind = []
        ind[0] = self.size
        for i in range(1, self.size - 1):
            if self.link[i].val is None:
                ind.append(i)
                break
        return ind

    # insert the element to the designated location
    def insert(self, ind, element):
        sua = -1
        # the last element
        pre = self.size - 1
        # the location of inserted element (the first empty location)
        insertLoc = self.link[0].next
        # conditional judgment
        if ind < 1 or ind >=pre or insertLoc >= self.size:
            return 0    # Illegal insertion
        # the first element's index
        for i in range(1, self.size - 1):
            index = self.link[pre].next
            if i == ind:
                self.link[pre].next = insertLoc
                # element insert
                self.link[insertLoc].val = element
                self.link[insertLoc].next = index
                # the first element
                # 首位元素
                self.link[0].next = self.findEmpty()
                sua = 1
                break
            if self.link[index].val is None:
                break
            pre = index
            return sua

            # 查找线性表某位置的元素

    def getByIndex(self, ind):
        if ind < 1 or ind >= self.size - 1:
            return -1

        index = self.link[self.size - 1].next
        if index == 0:
            return -1
        for i in range(1, ind):
            index = self.link[index].next

        return self.link[index].val

        # 查找线性表的元素所在位置

    def locateElement(self, ele):
        index = self.link[self.size - 1].next
        ind = -1
        if index == 0:
            return ind
        for i in range(1, self.size - 1):
            if self.link[index].val == ele:
                ind = i
                break
            if self.link[index].val is None:
                break
            index = self.link[index].next
        return ind

        # 删除线性表指定位置的元素

    def deleteElement(self, ind):
        sua = -1
        # 前一个索引
        pre = self.size - 1
        for i in range(1, self.size - 1):
            index = self.link[pre].next
            # 当前位置是个空位置
            if self.link[index].val is None:
                break
            # 已经遍历到第i个位置
            if i == ind:
                self.link[pre].next = self.link[index].next
                self.link[index].val = None
                # 删除元素的游标指向备用链表
                self.link[index].next = self.link[0].next
                # 首位元素
                self.link[0].next = index
                sua = 1
                break
            pre = index
        return sua

        # 按照线性表排序线性表遍历

    def travelLink(self):
        print("*" * 50)
        index = self.link[self.size - 1].next
        while self.link[index].val:
            print(
                f"value = {self.link[index].val} next = {self.link[index].next}"
            )
            index = self.link[index].next
        print("*" * 50)

        # 按照索引遍历

    def traversingByIndex(self):
        print("*" * 50)
        for i in range(self.size):
            print(
                f"index = {i}, value = {self.link[i].val} next = {self.link[i].next}"
            )
        print("*" * 50)

if __name__ == '__main__':
    ll = SLinkList()
    ll.traversingByIndex()
    print(ll.isEmpty())
    print(ll.insert(1, 'A'))
    ll.travelLink()
    print(ll.insert(2, 'B'))
    ll.travelLink()
    print(ll.insert(1, 'C'))
    print(ll.insert(4, 'D'))
    ll.travelLink()
    ll.traversingByIndex()
    print(ll.deleteElement(3))
    ll.traversingByIndex()
    ll.travelLink()
    print(ll.isEmpty())
    print(ll.getByIndex(2))
    print(ll.locateElement('BcA'))
    print(ll.clearSLL())














