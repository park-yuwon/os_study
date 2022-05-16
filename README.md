# os_study

- https://www.geeksforgeeks.org/gate-gate-cs-2005-question-72/ 부모와 자식에서 'a'의 물리적 주소는 달라야 합니다. 그러나 우리 프로그램은 가상 주소에 액세스합니다(가상 메모리를 사용하는 OS에서 실행 중이라고 가정). 자식 프로세스는 부모 프로세스의 정확한 복사본을 가져오고 'a'의 가상 주소는 자식 프로세스에서 변경되지 않습니다. 따라서 부모와 자식 모두에서 동일한 주소를 얻습니다. 그러나 python3에서 v와 y는 같지 않습니다. 이것을 참조 (Python의 경우) 및 참조  (C의 경우).
- The physical addresses of ‘a’ in parent and child must be different. But our program accesses virtual addresses (assuming we are running on an OS that uses virtual memory). The child process gets an exact copy of parent process and virtual address of ‘a’ doesn’t change in child process. Therefore, we get same addresses in both parent and child. But in python3 v and y will not be equal. See this (for Python) and See this (for C).
- https://www.geeksforgeeks.org/fork-system-call/


### Multi thread for Machine Learning
- Conclusion: We have just seen that multithreading could help to reduce the time taken per epoch in model training. Note that this method will not help much if:
  - there’s no more CPU resources left for another thread to be spawned
  - the original time taken is dominated by a process. If model training takes 10 seconds and data loading 0.1 second, then what normally consumes 101 seconds in total (for 10 epochs) will become 100 seconds. That’s equivalent to just about 1% improvement. In other words, the max of all processes’ time should ideally be way smaller than the their sum in order for multithreading to be effective.
- (https://towardsdatascience.com/speeding-up-model-training-with-multithreading-462df558d4f4) ![image](https://user-images.githubusercontent.com/77564623/168698974-514c41a3-682d-44c1-b4f1-80113a009ec6.png)
