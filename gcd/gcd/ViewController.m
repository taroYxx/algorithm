//
//  ViewController.m
//  gcd
//
//  Created by Taro on 2017/3/15.
//  Copyright © 2017年 Taro. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    dispatch_queue_t q = dispatch_queue_create("gcd", DISPATCH_QUEUE_CONCURRENT);
    dispatch_queue_t queue = dispatch_get_main_queue();
    dispatch_async(queue, ^{
        NSLog(@"%@",[NSThread currentThread]);
        for (int i=0; i<10; i++) {
            NSLog(@"%d",i);
        }
    });
    
    dispatch_barrier_async(queue, ^{
        NSLog(@"aaaa");//会讲队列分成三部分，1.首先等目前追加到并行队列中所有的任务都执行完 2.开始执行barrier中的任务，这时候即使向并行队列提交任务，也不会执行 3 barrier中的任务执行完成后，并行队列恢复正常
    });
    
    dispatch_async(queue, ^{
        NSLog(@"%@",[NSThread currentThread]);
        for (int i=10;i<20 ; i++) {
            NSLog(@"%d",i);
        }
    });
    
    
    dispatch_group_t group = dispatch_group_create();
    dispatch_group_async(group, queue, ^{
//        for (int i=0; i<10; i++) {
//            NSLog(@"group1");
//        }
//        
        
    });
    dispatch_group_async(group, queue, ^{
//        for (int i=0; i<10; i++) {
//            NSLog(@"group2");
//        }
    });
    
    dispatch_group_notify(group, queue, ^{
        NSLog(@"完成");
    });
    
    
    dispatch_semaphore_t semphore = dispatch_semaphore_create(2);
    dispatch_semaphore_wait(semphore, DISPATCH_TIME_FOREVER);
    
//
//    dispatch_group_wait(group, 2);
//    dispatch_time_t time = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3*NSEC_PER_SEC));
//    dispatch_after(time, queue, ^{
//        NSLog(@"123");
//    });
    
//    NSBlockOperation *operation = [NSBlockOperation blockOperationWithBlock:^{
//        NSLog(@"%@",[NSThread currentThread]);
//    }];
//    [operation addExecutionBlock:^{
//        NSLog(@"execution block %@",[NSThread currentThread]);
//    }];
//    [operation start];
    
                        
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
