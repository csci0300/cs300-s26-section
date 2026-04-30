struct List<'a> {
    val: i32,
    next: Option<&'a List<'a>>,
}

/// Makes a list with the first element `first_value`, and the second element `first_value + 1`
fn make_two_elt_list<'a>(first_value: i32) -> List<'a> {
    let list_node_2 = List {
        val: first_value + 1,
        next: None,
    };

    let list_node_1 = List {
        val: first_value,
        next: Some(&list_node_2),
    };

    return list_node_1;
}

#[allow(unused_variables)]
fn main() {

    let my_list = make_two_elt_list(1);
    println!("First list element: {}", my_list.val);
    println!("Second list element: {}", my_list.next.unwrap().val);
}