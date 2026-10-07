# MAJORITY ELEMENT-I

## 1. Problem

Given an integer array `nums` of size `n`, find the element that appears **more than n/2 times**.

The array is guaranteed to have a majority element.

---

# 2. APPROACH 1 — MAP / FREQUENCY COUNT

### My Idea

Mujhe sabse pehle `map` ka idea aaya tha.

Logic:

> Har element ki frequency count karo aur jiski frequency `n/2` se zyada ho, wahi majority element hai.
> 

### Mapping

```
element → frequency
```

Example:

```
nums = [2,2,1,1,1,2,2]

map:
2 → 4
1 → 3
```

Since:

```
n = 7
n/2 = 3
```

`2` ki frequency `4 > 3`.

Therefore:

```
answer = 2
```

---

## Important Syntax

```cpp
mp[nums[i]]++;
```

Meaning:

> `nums[i]` ki frequency ko 1 se increase karo.
> 

Map traversal:

```cpp
for(auto it : mp)
```

Here:

```
it.first  → element
it.second → frequency
```

So:

```cpp
if(it.second > nums.size()/2)
    return it.first;
```

means:

> Agar element ki frequency `n/2` se greater hai, us element ko return karo.
> 

### Complexity

```
Time  : O(n log n)
Space : O(n)
```

---

# 3. APPROACH 2 — SORTING + FREQUENCY

## My Second Idea

Maine socha:

1. Array ko sort karungi.
2. Same elements paas-paas aa jayenge.
3. Consecutive equal elements ki frequency count karungi.
4. `maxFreq` maintain karungi.
5. Jiski frequency maximum hogi, wahi answer.

Example:

```
Original:
[2,2,1,1,1,2,2]

After sorting:
[1,1,1,2,2,2,2]
```

Ab same elements consecutive hain.

---

# 4. Correct Logic

Variables:

```
freq  → current element ki frequency
maxF  → ab tak ki maximum frequency
idx   → maximum frequency wala element
```

If:

```cpp
nums[i] == nums[i+1]
```

then:

```cpp
freq++;
```

Otherwise:

```cpp
freq = 1;
```

---

# 5. MY MISTAKES

## Mistake 1 — Out of Bounds

Maine likha:

```cpp
for(int i = 0; i < n; i++)
```

aur andar:

```cpp
nums[i+1]
```

Problem:

When:

```
i = n-1
```

then:

```cpp
nums[i+1] = nums[n]
```

But valid indices are:

```
0 to n-1
```

### Correct

```cpp
for(int i = 0; i < n-1; i++)
```

---

## Mistake 2 — `freq = 0`

Maine likha:

```cpp
else {
    freq = 0;
}
```

This is wrong.

Correct:

```cpp
else {
    freq = 1;
}
```

### Why?

Suppose:

```
[1,1,1,2,2]
       ↑
```

Jab `1` se `2` par move kiya, `2` already **1 time** appear hua hai.

Therefore:

```
new element → frequency = 1
```

not `0`.

---

## Mistake 3 — Answer Update

Maine equal condition ke andar:

```cpp
idx = nums[i];
```

kar diya tha.

Better logic:

```cpp
if(freq > maxF) {
    maxF = freq;
    idx = nums[i];
}
```

Meaning:

> Sirf tab answer update karo jab current frequency previous maximum se greater ho.
> 

---

# 6. CORRECT SORTING + FREQUENCY CODE

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int freq = 1;
        int maxF = 0;
        int idx = nums[0];

        for(int i = 0; i < n - 1; i++) {

            if(nums[i] == nums[i + 1]) {
                freq++;
            }
            else {
                freq = 1;
            }

            if(freq > maxF) {
                maxF = freq;
                idx = nums[i];
            }
        }

        return idx;
    }
};
```

---

# 7. APPROACH 3 — SORTING + MIDDLE ELEMENT

## Important Observation

Question guarantee karta hai:

> Majority element exists and appears more than `n/2` times.
> 

After sorting, majority element **must occupy the middle position**.

Therefore:

```cpp
sort(nums.begin(), nums.end());

return nums[nums.size()/2];
```

Example:

```
[1,1,1,2,2,2,2]

index:
0 1 2 3 4 5 6

n/2 = 3

nums[3] = 2
```

Answer:

```
2
```

### Complexity

```
Time  : O(n log n)
Space : O(1) extra*
```

---

# 8. WHAT I DID WELL

Mujhe problem dekhte hi **frequency counting** ka idea aaya.

I identified:

```
Frequency problem
        ↓
MAP
```

Then second idea:

```
Same elements together
        ↓
SORT
        ↓
COUNT
```

So my **problem-solving intuition was correct**.

---

# 9. WHERE I LAGGED

Meri main weakness logic nahi thi.

Main implementation ke small details mein stuck hui:

```
map syntax
frequency reset
array boundary
answer kab update karna hai
```

So mujhe future mein sirf algorithm yaad nahi karna hai.

Mujhe ye bhi check karna hai:

### Boundary

```
Kya main i+1 access kar rahi hoon?
→ Then loop n-1 tak.
```

### Frequency

```
New element mila?
→ Frequency = 1
```

### Maximum

```
Current frequency > max?
→ Answer update.
```

---

# 10. PATTERN RECOGNITION

### Frequency / occurrence

Think:

```
MAP
```

### Same elements ko group karna

Think:

```
SORT + COUNT
```

### Majority element guaranteed

Think:

```
SORT → nums[n/2]
```

---

# 11. ALL APPROACHES — COPY-READY CODE

## A. Map

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it : mp) {
            if(it.second > nums.size() / 2) {
                return it.first;
            }
        }

        return -1;
    }
};
```

## B. Sorting + Frequency

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int freq = 1;
        int maxF = 0;
        int idx = nums[0];

        for(int i = 0; i < n - 1; i++) {

            if(nums[i] == nums[i + 1]) {
                freq++;
            }
            else {
                freq = 1;
            }

            if(freq > maxF) {
                maxF = freq;
                idx = nums[i];
            }
        }

        return idx;
    }
};
```

## C. Sorting + Middle Element

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};
```

---

# ONE-MINUTE REVISION

```
MAJORITY ELEMENT
       ↓
Frequency?
       ↓
MAP → mp[x]++

OR

Same elements together?
       ↓
SORT
       ↓
COUNT FREQUENCY

OR

Majority guaranteed?
       ↓
SORT
       ↓
nums[n/2]
```

### GOLDEN RULE

> Frequency problem → think MAP.
> 

> Same elements together → think SORT + COUNT.
> 

> Majority guaranteed → sorted middle element can directly give the answer.
>
