from tkinter import *
import tkinter.ttk
window=Tk()
window.title('Sudoku')
window.geometry('400x400+300+300')
tkinter.ttk.Separator(window, orient=VERTICAL).grid(row=0, column=3, rowspan=12,sticky='ns')
tkinter.ttk.Separator(window, orient=VERTICAL).grid(row=0, column=7, rowspan=12,sticky='ns')
tkinter.ttk.Separator(window, orient=VERTICAL).grid(row=0, column=11, rowspan=12,sticky='ns')
tkinter.ttk.Separator(window, orient=HORIZONTAL).grid(row=3, column=0, columnspan=12,sticky='ew')
tkinter.ttk.Separator(window, orient=HORIZONTAL).grid(row=7, column=0, columnspan=12,sticky='ew')
tkinter.ttk.Separator(window, orient=HORIZONTAL,).grid(row=11, column=0, columnspan=12,sticky='ew')
l=[]
d={}
k=0
a=0
for i in range(11):
    for j in range(11):
         if i==3 or i==7:
             i+=1
         if j==3 or j==7:
             j+=1
         d[k]=0
         d[k]=Entry(window, width=2,justify=CENTER).grid(row=i, column=j, sticky=N+E+S+W, pady = 1.5, padx = 1.5)
         k+=1
for i in range(12):
    window.grid_columnconfigure(i, minsize=10, weight=1,pad =3)
    window.grid_rowconfigure(i, minsize=10, weight=1, pad=3)
window.mainloop()






  
