class Solution {
public:
int longestValidParentheses(string s) {
        int len = s.length();
        if(len<2)
          return 0;
        int max = 0;
        int *dp = new int[len];
        for(int k = 0;k<len;k++)//�Ѹ���������գ��洢Ϊ0
         dp[k] = 0;
        for(int i = len-2;i>=0;i--)
        {
          if(s[i] == '(')//ֻ�������Ŵ����������������д洢Ϊ0
          {
            int j = i+1+dp[i+1];//�����뵱ǰ������ƥ��������ŵ�λ�á����ܴ���Ҳ���ܲ�����
            if(j<len && s[j] == ')')//ȷ��λ�ò���Խ��
            {
              dp[i] = dp[i+1] + 2;//�ҵ�����ƥ��������ţ���ǰ�����д洢�������������һ��λ�ü�2����һ��λ�ÿ��ܴ洢������0
              if(j+1<len)//��������������ƥ��Ĺؼ�����
                dp[i] += dp[j+1];//��j�ĺ�������Ѿ�����������ƥ�䣬Ҫ�ǵü��ϡ�dp[j+1]�洢����j+1��ʼ��ƥ��
            }
            if(dp[i]>max)
              max = dp[i];//���������
          }
          
        }
        return max;
    }
};