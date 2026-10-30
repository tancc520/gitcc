import tkinter as tk

# 计算步数对应的距离和卡路里
def calculate():
    try:
        steps = float(inp_steps.get())          # 获取步数
        step_length = float(inp_length.get())   # 获取步长（米）
        
        # 计算总距离（米）
        distance = steps * step_length
        # 估算消耗卡路里（约 0.05 千卡/步）
        calories = steps * 0.05
        
        # 在文本框中显示结果
        result = f"步数: {steps:.0f} 步\n"
        result += f"步长: {step_length:.2f} 米/步\n"
        result += f"总距离: {distance:.2f} 米 ({distance/1000:.2f} 公里)\n"
        result += f"消耗卡路里: {calories:.2f} 千卡\n"
        result += "-" * 30 + "\n"
        
        txt.insert(tk.END, result)
        txt.see(tk.END)  # 滚动到底部
        
        # 清空输入框
        inp_steps.delete(0, tk.END)
        inp_length.delete(0, tk.END)
    except ValueError:
        txt.insert(tk.END, "请输入有效的数字！\n")
        txt.see(tk.END)

# 清空结果区域
def clear_result():
    txt.delete(1.0, tk.END)

# 创建主窗口
window = tk.Tk()
window.geometry('400x450')
window.title('步数计算器')

# 标题标签
lb_title = tk.Label(window, text='🏃 步数计算器', font=('微软雅黑', 16, 'bold'))
lb_title.place(relx=0.1, rely=0.02, relheight=0.08, relwidth=0.8)

# 步数输入
lb1 = tk.Label(window, text='请输入步数（步）:', font=('微软雅黑', 10))
lb1.place(relx=0.1, rely=0.13, relheight=0.06, relwidth=0.8)
inp_steps = tk.Entry(window, font=('微软雅黑', 10))
inp_steps.place(relx=0.1, rely=0.20, relheight=0.07, relwidth=0.8)

# 步长输入
lb2 = tk.Label(window, text='请输入步长（米/步）:', font=('微软雅黑', 10))
lb2.place(relx=0.1, rely=0.29, relheight=0.06, relwidth=0.8)
inp_length = tk.Entry(window, font=('微软雅黑', 10))
inp_length.place(relx=0.1, rely=0.36, relheight=0.07, relwidth=0.8)
inp_length.insert(0, "0.7")  # 默认步长 0.7 米

# 计算按钮
btn_calc = tk.Button(window, text='计算', command=calculate,
                     font=('微软雅黑', 11), bg='#4CAF50', fg='white')
btn_calc.place(relx=0.1, rely=0.46, relheight=0.08, relwidth=0.35)

# 清空按钮
btn_clear = tk.Button(window, text='清空结果', command=clear_result,
                      font=('微软雅黑', 11), bg='#f44336', fg='white')
btn_clear.place(relx=0.55, rely=0.46, relheight=0.08, relwidth=0.35)

# 结果显示区域
txt = tk.Text(window, font=('微软雅黑', 10))
txt.place(relx=0.05, rely=0.57, relheight=0.40, relwidth=0.9)

window.mainloop()
