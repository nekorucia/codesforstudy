from urllib.request import urlopen
from urllib.parse import urlparse
from bs4 import BeautifulSoup
import re
import datetime
import random

pages = set()
random.seed(datetime.datetime.now())

#���������� �߰ߵ� ���� ��ũ�� ��� ������� ����ϴ�
def getInternalLinks(bs, includeUrl):
    includeUrl = '{}://{}'.format(urlparse(includeUrl).scheme,urlparse(includeUrl).netloc)
    internalLinks = []
    # /�� ���۵Ǵ� ��ũ�� ��� ã���ϴ�
    for link in bs.findAll('a', href=re.compile('^(/|.*)'+includeUrl+')')):
        if link.attrs['href'] is not None:
            if link.attrs['href'] not in internalLinks:
                if(link.attrs['href'].startswith('/')):
                    internalLinks.append(includeUrl+link.attrs['href'])
    return internalLinks


#���������� �߰ߵ� �ܺ� ��ũ�� ��� ������� ����ϴ�
def getExternalLinks(bs, excludeUrl):
    externalLinks = []
    # ���� url�� �������� �����鼭 http�� www�� �����ϴ� ��ũ�� ��� ã���ϴ�
    for link in bs.findAll('a', href=re.compile('^(http|www)((?!'+excludeUrl+').)*$')):
        if link.attrs['href'] is not None:
            if link.attrs['href'] not in externalLinks:
                externalLinks.append(link.attrs['href'])
    return externalLinks

def getRandomExternalLink(startingPage):
    html = urlopen(startingPage)
    bs = BeautifulSoup(html,'html.parser')
    externalLinks = getExternalLinks(bs, urlparse(startingPage).netloc)
    if len(externalLinks) == 0:
        print('no external links')
        domain = '{}://{}'.format(urlparse(includeUrl).scheme,urlparse(includeUrl).netloc)
        internalLinks = getInternalLinks(bs, domain)
        return getRandomExternalLink(internalLinks[random.randint(0,len(internalLinks)-1)])
    else:
        return externalLinks[random.randint(0,len(externalLinks)-1)]

def followExternalOnly(startingSite):
    externalLink = getRandomExternalLink(startingSite)
    print('random external link is : {}'.format(externalLink))
    followExternalOnly(externalLink)

followExternalOnly('https://news.naver.com/')