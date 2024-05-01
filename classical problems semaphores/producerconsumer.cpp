#include <iostream>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <semaphore.h>

struct DataBuffer {
    int data;
    sem_t mutex;
    sem_t items;
    sem_t slots;
};

void initializeSemaphores(DataBuffer* buffer) {
    sem_init(&buffer->mutex, 1, 1);
    sem_init(&buffer->items, 1, 0);
    sem_init(&buffer->slots, 1, 1);
}

void producerFunction(DataBuffer* buffer, int n) {
    for (int i = 1; i <= n; ++i) {
        sem_wait(&buffer->slots);
        sem_wait(&buffer->mutex);
        buffer->data = i;
        std::cout << "Produced: " << i << std::endl;
        sem_post(&buffer->mutex);
        sem_post(&buffer->items);
        sleep(1);
    }
}

void consumerFunction(DataBuffer* buffer) {
    while (true) {
        sem_wait(&buffer->items);
        sem_wait(&buffer->mutex);
        std::cout << "Consumed: " << buffer->data << std::endl;
        sem_post(&buffer->mutex);
        sem_post(&buffer->slots);
        sleep(2);
    }
}

int main() {
    int fd = shm_open("/producer_consumer_buffer", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(DataBuffer));
    DataBuffer* buffer = reinterpret_cast<DataBuffer*>(mmap(nullptr, sizeof(DataBuffer), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
    initializeSemaphores(buffer);
    pid_t pid = fork();
    if (pid == 0) {
        consumerFunction(buffer);
    } else {
        producerFunction(buffer, 10);
    }
    wait(nullptr);
    sem_destroy(&buffer->mutex);
    sem_destroy(&buffer->items);
    sem_destroy(&buffer->slots);
    munmap(buffer, sizeof(DataBuffer));
    close(fd);
    shm_unlink("/producer_consumer_buffer");
    return 0;
}
