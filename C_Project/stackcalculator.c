int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen=strlen(exp);
    int i;
    char tok,op1,op2;

    StackInit(&stack);

    for(i=0;i<expLen;i++) // ������ �����ϴ� ���� ������ ������� �ݺ�
    {
        tok=exp[i]; // �� ���ھ� tok�� ����
        if(isdigit(tok)) // ���ڰ� �������� Ȯ��
        {
            SPush(&stack, tok-'0'); //������ ���ڷ� ��ȯ �� ���ÿ� Ǫ��
        }
        else // �������� ��� 
        {
            op2 = SPop(&stack); // ���ÿ��� �ι�° ������ ������
            op1 = SPop(&stack); // ���ÿ��� ù��° ������ ������ 
        
        
            switch(tok) // �����ϰ� ����� ���ÿ� Ǫ��
            {
                case '+':
                    SPush(&stack,op1+op2);
                    break;
                case '-':
                    SPush(&stack,op1-op2);
                    break;
                case '*':
                    SPush(&stack,op1*op2);
                    break;
                case '/':
                    SPush(&stack,op1/op2);
                    break;
            }
        }
    }
    return SPop(&stack); // ������ �������� ���ÿ��� ���� ���� 
}