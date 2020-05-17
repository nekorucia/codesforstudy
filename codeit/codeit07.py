class Post:
    # �Խñ� Ŭ����
    def __init__(self, date, content):
        # �Խñ��� �Ӽ����� �ۼ� ��¥�� ������ ���´�
        self.date = date
        self.content = content

    def __str__(self):
        # �Խñ��� ������ ���ڿ��� �����ϴ� �޼ҵ�
        return "�ۼ� ��¥: {}\n����: {}".format(self.date, self.content)
    
    
class BlogUser:
    # ��α� ���� Ŭ����
    def __init__(self, name):
        """
        ��α� ������ �Ӽ����� �̸�, �Խñ۵��� ���´�
        posts�� �� �迭�� �ʱ�ȭ�Ѵ�
        """
        self.name=name
        self.posts=[]

    def add_post(self, date, content):
        # ���ο� �Խñ� �߰�
        post=Post(date,content)
        self.posts.append(post)

    def show_all_posts(self):
        # ��α� ������ ��� �Խñ� ���
        for p in self.posts:
            print(p)

    def __str__(self):
        # ������ �λ�� �̸��� ���ڿ��� ����
        return '�ȳ��ϼ��� {}�Դϴ�.'.format(self.name)
    
    

# ��α� ���� �ν��Ͻ� ����
blog_user_1 = BlogUser("����ȣ")

# ��α� ���� �ν��Ͻ� ���(�λ�, �̸�)
print(blog_user_1)

# ��α� ���� �Խñ� 2�� �߰�
blog_user_1.add_post("2019�� 8�� 30��", """
������ �� �����̿���.
���� ������� ���������.
�ູ�ߴ�.
""")

blog_user_1.add_post("2019�� 8�� 31��", """
��մ� �ڵ� ���� ����Ʈ�� ã�Ҵ�.
�ڵ����̶� ���ε� �ְ��.
���� �����Ͻ� �е��� www.codeit.kr�� ������!
""")

# ��α� ������ ��� �Խñ� ���
blog_user_1.show_all_posts()