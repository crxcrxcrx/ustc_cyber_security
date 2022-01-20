% 仿真实验系统的参数
alpha = 0.21;       %光纤信道损耗;      dB/km
Y_0 = 8.5*10^-7;    %背景噪声计数;      /gate
eta_Bob = 0.045;    %接收端探测效率;
e_Det= 3.3*10^-2;   %错误探测信号几率;
f__E_mu__ = 1.22;   %纠错效率;

% 自行填补数据
Arr_l = zeros(1, 2000);
Arr_R = zeros(1, 2000);
for i = 1:2000
    Arr_l(i) = i * 0.1;
end

% 临时数据
mu_max=0;
nu_max=0;
l=0;

% 开始计算
for mu=0.005:0.005:1
    for nu=0.005:0.005:(mu-0.001)
        for i = 1:2000
            % 仿真不同光纤距离l的实验观察参数
            eta = 10 ^ (-alpha * Arr_l(i) / 10) * eta_Bob;
            Q_mu = Y_0 + 1 - exp(-eta * mu);
            Q_nu = Y_0 + 1 - exp(-eta * nu);
            E_mu = (Y_0 / 2 + e_Det * (1 - exp(-eta * mu))) / Q_mu;
            E_nu = (Y_0 / 2 + e_Det * (1 - exp(-eta * nu))) / Q_nu;

            % 根据相关公式计算信号态安全密钥率
            p_mu__l__ = exp(-mu) * mu;
            Y_l = mu / (mu * nu - nu ^ 2) * (exp(nu) * Q_nu - nu ^ 2 / mu ^ 2 * exp(mu) * Q_mu - (mu ^ 2 - nu ^ 2) / mu ^ 2 * Y_0);
            e_l = (E_nu * Q_nu * exp(nu) - Y_0 / 2) / nu * Y_l;
            Arr_R(i) = max(0, 1/2 * (-Q_mu * f__E_mu__ * Entropy2(E_mu) + p_mu__l__ * Y_l * (1 - Entropy2(e_l))));
            if Arr_R(i) == 0
                if Arr_l(i)>l
                    l=Arr_l(i);
                    mu_max=mu;
                    nu_max=nu;
                end
                break;
            end
        end
    end
end
disp(mu_max);
disp(nu_max);
disp(l);

% 计算信息熵的函数
function e = Entropy2(p)
    if(p > 1 || p < 0)
        e=0;
    end
    e = -p * log2(p) - (1 - p) * log2(1 - p);
end