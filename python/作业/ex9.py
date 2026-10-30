import tkinter as tk
from tkinter import ttk, messagebox

def convert_temperature():
    celsius_input = entry_celsius.get().strip()
    if not celsius_input:
        messagebox.showerror("输入错误", "请输入摄氏温度！")
        return
    try:
        celsius = float(celsius_input)
    except ValueError:
        messagebox.showerror("输入错误", "请输入有效的数字！")
        return
    target = combo_target.get()
    if target == "华氏度":
        result = celsius * 9 / 5 + 32
        result_text = f"转换结果：{celsius:.2f} ℃ = {result:.2f} ℉"
    elif target == "开尔文":
        result = celsius + 273.15
        result_text = f"转换结果：{celsius:.2f} ℃ = {result:.2f} K"
    else:
        messagebox.showerror("选择错误", "请选择转换方式！")
        return
    label_result.config(text=result_text)

root = tk.Tk()
root.title("摄氏温度转换器")
root.geometry("400x200")
root.resizable(False, False)

label_celsius = ttk.Label(root, text="摄氏温度：")
label_celsius.place(x=30, y=30)

entry_celsius = ttk.Entry(root, width=15)
entry_celsius.place(x=110, y=30)

label_choose = ttk.Label(root, text="转换为：")
label_choose.place(x=30, y=70)

combo_target = ttk.Combobox(root, values=["华氏度", "开尔文"], width=13, state="readonly")
combo_target.place(x=110, y=70)
combo_target.current(0)

btn_convert = ttk.Button(root, text="转换", command=convert_temperature)
btn_convert.place(x=250, y=45)

label_result = ttk.Label(root, text="转换结果：", font=("", 10))
label_result.place(x=30, y=120)

root.mainloop()