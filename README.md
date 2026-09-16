# 📚 Stack Implementation Using Array in C



এই project-এ **C programming language** ব্যবহার করে একটি basic **Stack** implement করা হয়েছে।

Stack-এর data রাখার জন্য এখানে **Array** ব্যবহার করা হয়েছে এবং Stack-এর দুটি প্রধান operation implement করা হয়েছে:

* `PUSH` → Stack-এ নতুন value যোগ করা
* `POP` → Stack থেকে উপরের value বের করে দেওয়া

---

## 🧠 Stack কী?

**Stack** হলো একটি linear data structure যেখানে data **LIFO (Last In, First Out)** নিয়মে কাজ করে।

সহজভাবে:

> **যে item সবার শেষে Stack-এ ঢুকবে, সেটিই সবার আগে বের হবে।**

### 🍽️ বাস্তব জীবনের উদাহরণ

একটি প্লেটে একটার উপর আরেকটা করে খাবার রাখার কথা চিন্তা করো।

```text
       ┌───────┐
       │   30  │ ← সবার শেষে রাখা হয়েছে
       ├───────┤
       │   20  │
       ├───────┤
       │   10  │ ← সবার আগে রাখা হয়েছে
       └───────┘
```

এখন যদি একটি item বের করতে হয়, তাহলে উপরের `30`-ই আগে বের হবে।

এটাই **LIFO — Last In, First Out**।

---

# 🔄 Stack-এর প্রধান দুইটি Operation

## 1. PUSH

`PUSH` ব্যবহার করে Stack-এর মধ্যে নতুন item যোগ করা হয়।

উদাহরণ:

```text
PUSH 10

10
```

তারপর:

```text
PUSH 20

20  ← TOP
10
```

তারপর:

```text
PUSH 30

30  ← TOP
20
10
```

প্রতিবার নতুন item Stack-এর **উপরে** যোগ হয়।

---

## 2. POP

`POP` ব্যবহার করে Stack-এর **সবার উপরের item** remove করা হয়।

যদি Stack হয়:

```text
30  ← TOP
20
10
```

`POP` করার পর:

```text
20  ← TOP
10
```

অর্থাৎ `30` remove হয়েছে।

---

# 📌 `top` কী?

Stack-এর সবচেয়ে গুরুত্বপূর্ণ variable হলো:

```c
top
```

এটি Stack-এর বর্তমানে **top position/index** নির্দেশ করে।

Program শুরু হওয়ার সময়:

```c
top = -1;
```

এর অর্থ হলো Stack এখন **empty**।

### Example

কোনো item নেই:

```text
top = -1
```

একটি item push করার পর:

```text
top = 0
```

দুইটি item:

```text
top = 1
```

তিনটি item:

```text
top = 2
```

অর্থাৎ `top` সবসময় Stack-এর সর্বশেষ item-এর index নির্দেশ করে।

---

# 📦 Array দিয়ে Stack তৈরি

Program-এ:

```c
int stk[20];
```

ব্যবহার করা হয়েছে।

এটি Stack-এর data রাখার জন্য একটি integer array।

তবে এই program-এ:

```c
mx = 5;
```

দিয়ে Stack-এর maximum capacity **5** ধরা হয়েছে।

তাই Stack সর্বোচ্চ ৫টি item ধারণ করবে।

Array-এর index হবে:

```text
0   1   2   3   4
```

---

# 🚦 Program শুরু হলে

```c
top = -1;
```

থাকার কারণে Stack শুরুতে empty থাকে।

তারপর program বারবার user-এর কাছে choice জানতে চায়:

```text
Enter your choice:

1. PUSH
2. POP
3. EXIT
```

User-এর choice অনুযায়ী `switch` ব্যবহার করে `push()` অথবা `pop()` function call করা হয়।

---

# ➕ PUSH কীভাবে কাজ করে?

`push()` function নতুন item Stack-এ যোগ করার কাজ করে।

প্রথমে check করা হয় Stack full কিনা:

```c
if(top == mx - 1)
```

যদি Stack full হয়, তাহলে নতুন item যোগ করা যাবে না।

এটাকে বলা হয়:

### 🚨 Overflow

Stack-এর capacity পূর্ণ হয়ে যাওয়ার পর নতুন item যোগ করার চেষ্টা করলে **Stack Overflow** হয়।

Stack full না হলে:

```c
top = top + 1;
```

এর মাধ্যমে `top` এক position সামনে যায়।

তারপর user-এর কাছ থেকে value নেওয়া হয়:

```c
scanf("%d", &item);
```

এবং value-টি Stack-এ রাখা হয়:

```c
stk[top] = item;
```

---

# ➖ POP কীভাবে কাজ করে?

`pop()` function Stack-এর top থেকে item remove করে।

প্রথমে check করা হয়:

```c
if(top == -1)
```

যদি `top == -1` হয়, তাহলে Stack-এ কোনো item নেই।

এটাকে বলা হয়:

### 🚨 Underflow

Empty Stack থেকে কোনো item remove করার চেষ্টা করলে **Stack Underflow** হয়।

Stack empty না হলে:

```c
item = stk[top];
```

এর মাধ্যমে top-এর item নেওয়া হয়।

তারপর:

```c
top = top - 1;
```

এর মাধ্যমে `top` এক position নিচে চলে যায়।

ফলে আগের top item Stack থেকে remove হয়ে যায়।

---

# 🧪 Detailed Dry Run

এখন আমরা পুরো program-টি একটি example দিয়ে step-by-step dry run করব।

ধরি, user নিচের operations করবে:

```text
PUSH 10
PUSH 20
PUSH 30
POP
PUSH 40
POP
POP
```

Program শুরু হওয়ার সময়:

```text
mx = 5
top = -1
```

Stack এখন empty।

---

## 🟢 Step 1 — PUSH 10

User menu থেকে:

```text
1
```

select করে।

তাই `push()` function call হবে।

### প্রথমে condition check:

```c
if(top == mx - 1)
```

বর্তমানে:

```text
top = -1
mx - 1 = 4
```

তাই:

```text
-1 == 4
```

❌ False

Stack full নয়।

### এরপর:

```c
top = top + 1;
```

তাই:

```text
top = 0
```

User input দেয়:

```text
10
```

তারপর:

```c
stk[top] = item;
```

অর্থাৎ:

```text
stk[0] = 10
```

### বর্তমান Stack:

```text
Index       Value

  0          10  ← TOP
```

```text
top = 0
```

---

# 🟢 Step 2 — PUSH 20

আবার user:

```text
1
```

দিয়ে PUSH select করে এবং input দেয়:

```text
20
```

বর্তমানে:

```text
top = 0
```

Stack full কিনা check:

```text
0 == 4
```

❌ False

তারপর:

```c
top = top + 1;
```

ফলে:

```text
top = 1
```

তারপর:

```c
stk[1] = 20
```

### বর্তমান Stack:

```text
Index       Value

  1          20  ← TOP
  0          10
```

```text
top = 1
```

---

# 🟢 Step 3 — PUSH 30

আবার PUSH select করা হলো।

Input:

```text
30
```

বর্তমানে:

```text
top = 1
```

Full check:

```text
1 == 4
```

❌ False

তারপর:

```c
top = top + 1;
```

ফলে:

```text
top = 2
```

তারপর:

```c
stk[2] = 30
```

### বর্তমান Stack:

```text
Index       Value

  2          30  ← TOP
  1          20
  0          10
```

```text
top = 2
```

---

# 🔴 Step 4 — POP

এবার user:

```text
2
```

দিয়ে POP select করে।

তাই `pop()` function call হবে।

প্রথমে check:

```c
if(top == -1)
```

বর্তমানে:

```text
top = 2
```

তাই:

```text
2 == -1
```

❌ False

অর্থাৎ Stack empty নয়।

### Top item নেওয়া:

```c
item = stk[top];
```

অর্থাৎ:

```text
item = stk[2]
item = 30
```

এখন:

```c
top = top - 1;
```

তাই:

```text
top = 1
```

ফলে `30` Stack থেকে remove হয়েছে।

### বর্তমান Stack:

```text
Index       Value

  1          20  ← TOP
  0          10
```

Removed item:

```text
30
```

---

# 🟢 Step 5 — PUSH 40

আবার PUSH select করা হলো।

Input:

```text
40
```

বর্তমানে:

```text
top = 1
```

Full check:

```text
1 == 4
```

❌ False

তারপর:

```c
top = top + 1;
```

ফলে:

```text
top = 2
```

তারপর:

```c
stk[2] = 40
```

### বর্তমান Stack:

```text
Index       Value

  2          40  ← TOP
  1          20
  0          10
```

---

# 🔴 Step 6 — POP

User আবার:

```text
2
```

দিয়ে POP করে।

বর্তমানে:

```text
top = 2
```

তাই Stack empty নয়।

Top item:

```c
item = stk[top];
```

অর্থাৎ:

```text
item = stk[2]
item = 40
```

তারপর:

```c
top = top - 1;
```

ফলে:

```text
top = 1
```

`40` remove হয়ে গেল।

### বর্তমান Stack:

```text
Index       Value

  1          20  ← TOP
  0          10
```

---

# 🔴 Step 7 — POP

আবার POP করা হলো।

বর্তমানে:

```text
top = 1
```

Top item:

```text
item = stk[1]
item = 20
```

তারপর:

```text
top = top - 1
```

ফলে:

```text
top = 0
```

`20` remove হয়ে গেল।

### Final Stack:

```text
Index       Value

  0          10  ← TOP
```

---

# 📊 Dry Run Summary

| Step | Operation | Item | `top` Before | `top` After | Stack      |
| ---: | --------- | ---: | -----------: | ----------: | ---------- |
|    1 | PUSH      |   10 |           -1 |           0 | 10         |
|    2 | PUSH      |   20 |            0 |           1 | 10, 20     |
|    3 | PUSH      |   30 |            1 |           2 | 10, 20, 30 |
|    4 | POP       |   30 |            2 |           1 | 10, 20     |
|    5 | PUSH      |   40 |            1 |           2 | 10, 20, 40 |
|    6 | POP       |   40 |            2 |           1 | 10, 20     |
|    7 | POP       |   20 |            1 |           0 | 10         |

এখানে লক্ষ্য করলে দেখা যায়:

```text
PUSH: 10 → 20 → 30 → 40
POP : 30 → 40 → 20
```

প্রতিবার **সর্বশেষ যোগ করা item আগে বের হচ্ছে**, যা Stack-এর **LIFO** rule প্রমাণ করে।

---

# 🚨 Overflow Dry Run

ধরি Stack-এর capacity:

```text
mx = 5
```

এবং আমরা ৫টি item push করেছি:

```text
50
40
30
20
10
```

তখন:

```text
top = 4
```

কারণ শেষ valid index হলো `4`।

এখন আবার PUSH করলে condition:

```c
if(top == mx - 1)
```

হবে:

```text
4 == 4
```

✅ True

তাই নতুন item যোগ হবে না এবং:

```text
Stack is full/overflow
```

message দেখাবে।

---

# 🚨 Underflow Dry Run

ধরি Stack সম্পূর্ণ empty:

```text
top = -1
```

এখন user যদি POP করে:

```c
if(top == -1)
```

হবে:

```text
-1 == -1
```

✅ True

তাই কোনো item remove করার চেষ্টা না করে:

```text
Stack is empty/underflow
```

message দেখাবে।

---

# 🔁 Program Flow

পুরো program-এর কাজ সহজভাবে:

```text
             START
               ↓
        Display Menu
               ↓
       ┌───────┼───────┐
       ↓       ↓       ↓
     PUSH     POP     EXIT
       ↓       ↓
     Check    Check
      Full?   Empty?
       ↓       ↓
      Add     Remove
       ↓       ↓
       └──→ Menu ←────┘
```

Program `EXIT` না দেওয়া পর্যন্ত menu বারবার দেখাবে।

---

# 🧩 Important Variables

| Variable | কাজ                               |
| -------- | --------------------------------- |
| `stk[]`  | Stack-এর values রাখে              |
| `top`    | Stack-এর top position নির্দেশ করে |
| `mx`     | Stack-এর maximum capacity         |
| `item`   | Push/Pop-এর সময় value রাখে        |
| `c`      | User-এর menu choice রাখে          |
| `i`      | Loop চালানোর জন্য ব্যবহৃত হয়      |

---

# 🚨 Overflow vs Underflow

| Situation                        | নাম           | অর্থ                  |
| -------------------------------- | ------------- | --------------------- |
| Full Stack-এ নতুন item যোগ করা   | **Overflow**  | Stack-এর capacity শেষ |
| Empty Stack থেকে item remove করা | **Underflow** | Stack-এ কোনো item নেই |

---

## ⚠️ Note

এই project-টি basic **Stack using Array** implementation বোঝানোর জন্য তৈরি করা হয়েছে।

Program-এর current implementation-এ Stack-এর maximum capacity `5` ধরা হয়েছে।

আরও advanced implementation-এ Dynamic Array, Linked List অথবা `struct` ব্যবহার করে Stack তৈরি করা যেতে পারে।
