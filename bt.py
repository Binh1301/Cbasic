import math
from tabulate import tabulate

def f(x):
    return math.exp(x) + math.exp(-x) - 3 * x**2 + x

a = 2.0
b = 4.0
epsilon = 0.001
N_fib = 20

def exhaustive_search(f, a, b, epsilon):
    k = int(2 * (b - a) / epsilon) + 2
    
    delta_x = (b - a) / k
    
    x_star = a
    f_star = f(a)
    
    for i in range(1, k + 1):
        x = a + i * delta_x
        f_x = f(x)
        
        if f_x < f_star:
            f_star = f_x
            x_star = x
            
    return x_star, f_star

def fibonacci_search(f, a, b, N):
    fib = [0, 1]
    while len(fib) <= N + 1:
        fib.append(fib[-1] + fib[-2])
        
    L = b - a
    
    a_k, b_k = a, b
    lambda_k = a_k + (fib[N - 1] / fib[N + 1]) * L
    mu_k = a_k + (fib[N] / fib[N + 1]) * L
    
    f_lambda = f(lambda_k)
    f_mu = f(mu_k)
    
    for k in range(N - 1):
        if f_lambda > f_mu:
            a_k = lambda_k
            lambda_k = mu_k
            f_lambda = f_mu
            
            mu_k = a_k + (fib[N - (k + 1)] / fib[N - k]) * (b_k - a_k) 
            f_mu = f(mu_k)
            
        else:
            b_k = mu_k
            mu_k = lambda_k
            f_mu = f_lambda
            
            lambda_k = a_k + (fib[N - (k + 2)] / fib[N - k]) * (b_k - a_k)
            f_lambda = f(lambda_k)
        
    if f_lambda > f_mu:
        a_final = lambda_k
        b_final = b_k
    else:
        a_final = a_k
        b_final = mu_k
        
    x_star = (a_final + b_final) / 2 
    f_star = f(x_star)
    
    return x_star, f_star

def golden_section_search(f, a, b, epsilon):
    rho = 0.38196601125 
    
    a_k, b_k = a, b
    
    x1 = a_k + rho * (b_k - a_k)
    x2 = b_k - rho * (b_k - a_k)
    
    f1 = f(x1)
    f2 = f(x2)
    
    while (b_k - a_k) > epsilon:
        if f1 > f2:
            a_k = x1
            
            x1 = x2
            f1 = f2
            
            x2 = b_k - rho * (b_k - a_k)
            f2 = f(x2)
        else:
            b_k = x2
            
            x2 = x1
            f2 = f1
            
            x1 = a_k + rho * (b_k - a_k)
            f1 = f(x1)
            
    x_star = (a_k + b_k) / 2
    f_star = f(x_star)
    
    return x_star, f_star
print(f"Miền tìm kiếm: [{a}, {b}] | Sai số: {epsilon} | Số bước Fibonacci: {N_fib}\n")

try:
    x_es, f_es = exhaustive_search(f, a, b, epsilon)
    x_fib, f_fib = fibonacci_search(f, a, b, N_fib)
    x_gss, f_gss = golden_section_search(f, a, b, epsilon)

    data = [
        ["Cơ bản", x_es, f_es],
        [f"Fibonacci (N={N_fib})", x_fib, f_fib],
        ["Lát cắt vàng", x_gss, f_gss],
    ]

    headers = ["Phương pháp", "x*", "f(x*)"]
    
    print(tabulate(data, headers=headers, floatfmt=".6f", numalign="left"))

except Exception as e:
    print(f"Failed {e}")