class GameCharacter:
    # ���� ĳ���� Ŭ����
    def __init__(self, name, hp, power):
        # ���� ĳ���ʹ� �Ӽ����� �̸�, hp, ���ݷ��� ���´�
        self.name=name
        self.hp=hp
        self.power=power

    def is_alive(self):
        # ���� ĳ���Ͱ� ����ִ���(ü���� 0�� �Ѵ���) Ȯ���ϴ� �޼ҵ�
        return self.hp>0

    def get_attacked(self, damage):
        """
        ���� ĳ���Ͱ� ��������� ������ ĳ������ ���ݷ¸�ŭ ü���� ��� �޼ҵ�
        ����:    
            1. �̹� ĳ���Ͱ� �׾����� �׾��ٴ� �޽����� ����Ѵ�
            2. ���� ü�º��� ���ݷ��� �� ũ�� ü���� 0�� �ȴ�.
        """
        if self.is_alive():
            if self.hp>damage:
                self.hp =- damage
            else:
                self.hp=0
        else:
            print("{} is already dead".format(self.name))
            

    def attack(self, other_character):
        # ���� ĳ���Ͱ� ��������� �Ķ���ͷ� ���� �ٸ� ĳ������ ü���� �ڽ��� ���ݷ¸�ŭ ��´�.
        #other_character.get_attacked(self.power)
        if self.is_alive():
            other_character.get_attacked(self.power)


    def __str__(self):
        # ���� ĳ������ �ǹ��ִ� ������ ������ ���ڿ��� �����Ѵ�.
        return '{}���� hp�� {}��ŭ ���ҽ��ϴ�\.'.format(self.name,self.hp)

# ���� ĳ���� �ν��Ͻ� ����                        
character_1 = GameCharacter("Ww��������wW", 200, 30)
character_2 = GameCharacter("Xx�����ְ�xX", 100, 50)

# ���� ĳ���� �ν��Ͻ��� ���� ����
character_1.attack(character_2)
character_2.attack(character_1)
character_2.attack(character_1)
character_2.attack(character_1)
character_2.attack(character_1)
character_2.attack(character_1)

# ���� ĳ���� �ν��Ͻ� ���
print(character_1)
print(character_2)