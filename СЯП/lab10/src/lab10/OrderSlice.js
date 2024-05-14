import { createSlice } from "@reduxjs/toolkit";

export const OrderSlice = createSlice ({
    name: 'order',
    initialState: {
        orderInf: {
            delivery: '',
            address: '', 
            payment: ''
        },
        orders: []
    },
    reducers:{
        setAddress: (state, action) => {
            state.orderInf.address = action.payload
        },
        setDelivery: (state, action) => {
            state.orderInf.delivery = action.payload
        },
        setPayment: (state, action) => {
            state.orderInf.payment = action.payload
        },
        setOrders: (state, action) => {
            state.orders = state.orders.concat(action.payload)
        }
    }
}
)

export const {setAddress, setDelivery, setPayment, setOrders} = OrderSlice.actions

export default OrderSlice.reducer