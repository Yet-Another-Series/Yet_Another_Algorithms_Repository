/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package queueimplemetation;

import java.util.ArrayList;

/**
 *
 * @author Salman Ahmad
 */
public class Queue {

    QueueNode front;
    QueueNode rear;

    public Queue() {
        front = rear = null;
    }

    public void add(int data) {
        QueueNode node = new QueueNode();
        node.data = data;
        if (front == null) {
            front = node;
            rear = node;
        } else {
            rear.Next = node;
            rear = node;
        }
    }

    public QueueNode front() {
        return front;
    }

    public QueueNode rear() {
        return rear;
    }

    public void remove() {
        QueueNode temp = front;
        front = front.Next;
        temp.Next = null;
        temp = null;
    }

    public int size() {
        int size = 0;
        QueueNode temp = front;
        while (temp != null) {
            size++;
            temp = temp.Next;
        }
        return size;
    }

    public int elementAt(int index) {
        QueueNode temp = front;
        int i = 0;
        while (temp != null) {
            if (i == index) {
                return temp.data;
            } else {
                i++;
                temp=temp.Next;
            }
        }
        return -1;
    }
}
