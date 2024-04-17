1.	#include <iostream>
2.	using namespace std;
3.	
4.	// Program for a non-circular single linked list
5.	
6.	struct Node {
7.	    int data;
8.	    Node* next;
9.	};
10.	
11.	Node* head;
12.	Node* tail;
13.	
14.	// Initialize the head and tail pointers to NULL
15.	void init() {
16.	    head = NULL;
17.	    tail = NULL;
18.	}
19.	
20.	// Check if the linked list is empty
21.	bool isEmpty() {
22.	    if (head == NULL) {
23.	        return true;
24.	    } else {
25.	        return false;
26.	    }
27.	}
28.	
29.	// Add a new node at the beginning of the list
30.	void insertDepan(int value) {
31.	    Node* baru = new Node();
32.	    baru->data = value;
33.	    baru->next = NULL;
34.	
35.	    if (isEmpty() == true) {
36.	        head = tail = baru;
37.	        head->next = NULL;
38.	    } else {
39.	        baru->next = head;
40.	        head = baru;
41.	    }
42.	}
43.	
44.	// Add a new node at the end of the list
45.	void insertBelakang(int value) {
46.	    Node* baru = new Node();
47.	    baru->data = value;
48.	    baru->next = NULL;
49.	
50.	    if (isEmpty() == true) {
51.	        head = tail = baru;
52.	        head->next = NULL;
53.	    } else {
54.	        tail->next = baru;
55.	        tail = baru;
56.	    }
57.	}
58.	
59.	// Count the number of nodes in the list
60.	int hitungList() {
61.	    Node* hitung = head;
62.	    int count = 0;
63.	
64.	    while (hitung != NULL) {
65.	        count++;
66.	        hitung = hitung->next;
67.	    }
68.	
69.	    return count;
70.	}
71.	
72.	// Insert a new node in the middle of the list
73.	void insertTengah(int data, int position) {
74.	    if (position < 1 || position > hitungList()) {
75.	        cout << "Position out of range" << endl;
76.	    } else if (position == 1) {
77.	        cout << "Position is not in the middle" << endl;
78.	    } else {
79.	        Node* baru = new Node();
80.	        baru->data = data;
81.	
82.	        Node* traversal = head;
83.	        int nomor = 1;
84.	
85.	        while (nomor < position - 1) {
86.	            traversal = traversal->next;
87.	            nomor++;
88.	        }
89.	
90.	        baru->next = traversal->next;
91.	        traversal->next = baru;
92.	    }
93.	}
94.	
95.	// Delete the first node in the list
96.	void hapusDepan() {
97.	    Node* toDelete;
98.	
99.	    if (isEmpty() == false) {
100.	        if (head->next != NULL) {
101.	            toDelete = head;
102.	            head = head->next;
103.	            delete toDelete;
104.	        } else {
105.	            head = tail = NULL;
106.	        }
107.	    } else {
108.	        cout << "Linked list is still empty" << endl;
109.	    }
110.	}
111.	
112.	// Delete the last node in the list
113.	void hapusBelakang() {
114.	    Node* toDelete;
115.	    Node* traversal;
116.	
117.	    if (isEmpty() == false) {
118.	        if (head != tail) {
119.	            toDelete = tail;
120.	            traversal = head;
121.	
122.	            while (traversal->next != tail) {
123.	                traversal = traversal->next;
124.	            }
125.	
126.	            tail = traversal;
127.	            tail->next = NULL;
128.	            delete toDelete;
129.	        } else {
130.	            head = tail = NULL;
131.	        }
132.	    } else {
133.	        cout << "Linked list is still empty" << endl;
134.	    }
135.	}
136.	// Hapus tengah
137.	void hapusTengah(int posisi)
138.	{
139.	    Node *hapus, *bantu, *sebelum;
140.	    if (posisi < 1 || posisi > hitungList())
141.	    {
142.	        cout << "Posisi di luar jangkauan" << endl;
143.	    }
144.	    else if (posisi == 1)
145.	    {
146.	        cout << "Posisi bukan posisi tengah" << endl;
147.	    }
148.	    else
149.	    {
150.	        int nomor = 1;
151.	        bantu = head;
152.	        while (nomor <= posisi)
153.	        {
154.	            if (nomor == posisi - 1)
155.	            {
156.	                sebelum = bantu;
157.	            }
158.	            if (nomor == posisi)
159.	            {
160.	                hapus = bantu;
161.	            }
162.	            bantu = bantu->next;
163.	            nomor++;
164.	        }
165.	        sebelum->next = bantu;
166.	        delete hapus;
167.	    }
168.	}
169.	
170.	// ubah depan
171.	void ubahDepan(int data)
172.	{
173.	    if (isEmpty() == 0)
174.	    {
175.	        head->data = data;
176.	    }
177.	    else
178.	    {
179.	        cout << "Linked list masih kosong" << endl;
180.	    }
181.	}
182.	
183.	// ubah tengah
184.	void ubahTengah
185.	(int data, int posisi)
186.	{
187.	    Node *bantu;
188.	    if (isEmpty() == 0)
189.	    {
190.	        if (posisi < 1 || posisi > hitungList())
191.	        {
192.	            cout << "Posisi di luar jangkauan" << endl;
193.	        }
194.	        else if (posisi == 1)
195.	        {
196.	            cout << "Posisi bukan posisi tengah" << endl;
197.	        }
198.	        else
199.	        {
200.	            int nomor = 1;
201.	            bantu = head;
202.	            while (nomor < posisi)
203.	            {
204.	                bantu = bantu->next;
205.	                nomor++;
206.	            }
207.	            bantu->data = data;
208.	        }
209.	    }
210.	    else
211.	    {
212.	        cout << "Linked list masih kosong" << endl;
213.	    }
214.	}
215.	
216.	// ubah belakang
217.	void ubahBelakang(int data)
218.	{
219.	    if (isEmpty() == 0)
220.	    {
221.	        tail->data = data;
222.	    }
223.	    else
224.	    {
225.	        cout << "Linked list masih kosong" << endl;
226.	    }
227.	}
228.	
229.	// Hapus list 
230.	void clearList()
231.	{
232.	    Node *bantu, *hapus;
233.	    bantu = head;
234.	    while (bantu != NULL)
235.	    {
236.	        hapus = bantu;
237.	        bantu = bantu->next;
238.	        delete hapus;
239.	    }
240.	    head = tail = NULL;
241.	    cout << "List berhasil terhapus!" << endl;
242.	}
243.	
244.	// Tampilkan list 
245.	void tampilList()
246.	{
247.	    Node *bantu;
248.	    bantu = head;
249.	    if (isEmpty() == false)
250.	    {
251.	        while (bantu != NULL)
252.	        {
253.	            cout << bantu->data << " ";
254.	            bantu = bantu->next;
255.	        }
256.	        cout << endl;
257.	    }
258.	    else
259.	    {
260.	        cout << "Linked list masih kosong" << endl;
261.	    }
262.	}
263.	
264.	int main()
265.	{
266.	    init();
267.	    insertDepan(3);
268.	    tampilList();
269.	    insertBelakang(5);
270.	    tampilList();
271.	    insertDepan(2);
272.	    tampilList();
273.	    insertDepan(1);
274.	    tampilList();
275.	    hapusDepan();
276.	    tampilList();
277.	    hapusBelakang();
278.	    tampilList();
279.	    insertTengah(7, 2);
280.	    tampilList();
281.	    hapusTengah(2);
282.	    tampilList();
283.	    ubahDepan(1);
284.	    tampilList();
285.	    ubahBelakang(8);
286.	    tampilList();
287.	    ubahTengah(11, 2);
288.	    tampilList();
289.	
290.	    return 0;
291.	}
