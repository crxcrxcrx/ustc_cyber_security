% ����ʵ��ϵͳ�Ĳ���
alpha = 0.21;       %�����ŵ����;      dB/km
Y_0 = 8.5*10^-7;    %������������;      /gate
eta_Bob = 0.045;    %���ն�̽��Ч��;
e_Det= 3.3*10^-2;   %����̽���źż���;
mu = 0.6;           %�ź�̬ƽ����ǿ;    photon/pulse
nu = 0.2;           %��ƭ̬ƽ����ǿ;    photon/pulse
f__E_mu__ = 1.22;   %����Ч��;

% ���������
Arr_l = zeros(1, 2000);
Arr_R = zeros(1, 2000);
for i = 1:2000
    Arr_l(i) = i * 0.1;
end

% ��ʼ����
for i = 1:2000
    % ���治ͬ���˾���l��ʵ��۲����
    eta = 10 ^ (-alpha * Arr_l(i) / 10) * eta_Bob;
    Q_mu = Y_0 + 1 - exp(-eta * mu);
    Q_nu = Y_0 + 1 - exp(-eta * nu);
    E_mu = (Y_0 / 2 + e_Det * (1 - exp(-eta * mu))) / Q_mu;
    E_nu = (Y_0 / 2 + e_Det * (1 - exp(-eta * nu))) / Q_nu;

    % ������ع�ʽ�����ź�̬��ȫ��Կ��
    p_mu__l__ = exp(-mu) * mu;
    Y_l = mu / (mu * nu - nu ^ 2) * (exp(nu) * Q_nu - nu ^ 2 / mu ^ 2 * exp(mu) * Q_mu - (mu ^ 2 - nu ^ 2) / mu ^ 2 * Y_0);
    e_l = (E_nu * Q_nu * exp(nu) - Y_0 / 2) / nu * Y_l;
    Arr_R(i) = max(0, 1/2 * (-Q_mu * f__E_mu__ * Entropy2(E_mu) + p_mu__l__ * Y_l * (1 - Entropy2(e_l))));
    if Arr_R(i) == 0
        disp(Arr_l(i));
        break;
    end
end
semilogy (Arr_l, Arr_R)

% ������Ϣ�صĺ���
function e = Entropy2(p)
    if(p > 1 || p < 0)
        e=0;
    end
    e = -p * log2(p) - (1 - p) * log2(1 - p);
end