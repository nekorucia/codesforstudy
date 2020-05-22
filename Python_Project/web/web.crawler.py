import sys
sys.path.append("web\web_class.py")
import requests
from bs4 import BeautifulSoup

class Crawler:
    def getPage(self, url):
        try:
            req = requests.get(url)
        except requests.exceptions.RequestException:
            return None
        return BeautifulSoup(req.text,'html.parser')

    def safeGet(self,pageObj,selector):
        '''
        Beautifulsoup ��ü�� �����ڸ� �޾� ������ ���ڿ��� �����ϴ� �Լ�
        �־��� �����ڷ� �˻��� ����� ���ٸ� �� ���ڿ��� ��ȯ�մϴ�
        '''
        selectedElems=pageObj.select(selector)
        if selectedElems is not None and len(selectedElems)>0
            return '\n'.join([elem.get_text() for elem in selectedElems])
        return ''

    def parse(self, site, url): #url�� �޾� �������� �����մϴ�
        bs = self.getPage(url)
        if bs is not None:
            title=self.safeGet(bs,site.titleTag)
            body=self.safeGet(bs,site.bodyTag)
            if title!=''and body!='':
                content=Content(url,title,body)
                content.print()