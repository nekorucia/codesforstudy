class Content : #��/������ ��ü�� ����� ��� Ŭ����
    def __init__(self,url,title,body):
        self.url=url
        self.title=title
        self.body=body
    
    def print(self): #��� ����� ���ϴ� ��� �ٲ� �� �ִ� �Լ�
        print("URL : {}".format(self.url))
        print("TITLE : {}".format(self.title))
        print("BODY : \n{}".format(self.body))


class Website: #������Ʈ ������ ���� ������ ����
    def __init__(self,name,url,titleTag,bodyTag):
        self.name=name
        self.url=url
        self.titleTag=titleTag
        self.bodyTag=bodyTag

        