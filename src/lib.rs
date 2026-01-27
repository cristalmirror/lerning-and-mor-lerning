pub struct Object{
    id_sesion: i32,
    state: bool,
}

impl Object {
    
    fn new(id: i32) ->Self {
        Object {
            id_sesion: id,
            state: false,
        }
    }

    //pribvate methods
    fn activate(&mut self,n: i32) {
        self.state = true;
        println!("Object {} activated", self.id_sesion);
        self.processing_data(n);
    }

    fn deactivate(&mut self) {
        self.state = false;
        println!("Object {} deactivated", self.id_sesion);
    }
    fn processing_data(&self, n: i32) -> i32 {
        if self.state {
            println!("Processing data: {} in object {}", n, self.id_sesion);
            n * 2 // Example processing
        } else {
            println!("Object {} is not active. Cannot process data.", self.id_sesion);
            0
        }
        
    }

    //dispacher methods
    pub fn start_processing(&mut self,comand: i32, n: i32) -> i32 {
        match comand {
            1 => {
                self.activate(n);
                0
            },
            2 => {
                self.deactivate();
                0
            },
            _ => {
                println!("Invalid command");
                -1
            }
        }
    }
}

#[unsafe(no_mangle)]
pub extern "C" fn create_object(id: i32) -> *mut Object {
    Box::into_raw(Box::new(Object::new(id)))
}

#[unsafe(no_mangle)]
pub extern "C" fn object_comand(obj_ptr: *mut Object, cnmd: i32, n: i32) {
    let obj = unsafe {
        assert!(!obj_ptr.is_null());
        &mut *obj_ptr
    };
    obj.start_processing(cnmd, n);
} 

#[unsafe(no_mangle)]
pub extern "C" fn destroy_object(obj_ptr: *mut Object) {
    if !obj_ptr.is_null() {
        unsafe {
            let _ = Box::from_raw(obj_ptr);
        }
    }
}



#[unsafe(no_mangle)]
pub extern "C" fn sumar(a: i32, b: i32) -> i32 {
    
    println!("Hello, world!, from Rust! Code, your numbers are: {} and {}", a, b);
    return a + b;
}
#[unsafe(no_mangle)]
pub extern "C" fn loop_func() {
    for i in 1..10 {
        println!("Numero: [{}] Rust",i);
    }
}