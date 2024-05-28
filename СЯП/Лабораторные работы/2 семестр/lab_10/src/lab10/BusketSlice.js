import { createSlice } from "@reduxjs/toolkit";
import {list_of_products} from './Busketproducts.js' 

export const BusketSlice = createSlice ({
    name: 'busket',
    initialState: {
        busket: list_of_products,
        orderProducts: [],
    },
    reducers:{
        increment: (state, id) => {
            if (state.busket[id.payload].count_in_order < state.busket[id.payload].quantity)
            state.busket[id.payload].count_in_order += 1;
            state.orderProducts = state.busket.filter( product => product.checked === true)
          },
        decrement: (state, id) => {
            if (state.busket[id.payload].count_in_order > 1)
            state.busket[id.payload].count_in_order -= 1;
            state.orderProducts = state.busket.filter( product => product.checked === true)
          },
        remove: (state, id) => {
            state.busket = state.busket.filter(product => product !==  state.busket[id.payload])
        },
        removeOrder: (state, id) => {
            state.orderProducts = state.orderProducts.filter(product => product !==  state.orderProducts[id.payload])
        },
        addToOrder: (state, id) => {
            state.busket[id.payload].checked = !state.busket[id.payload].checked
            state.orderProducts = state.busket.filter( product => product.checked === true)
        },
        changeOrder: (state) => {
            state.orderProducts = state.busket.filter( product => product.checked === true)
            console.log ( state.orderProducts)
        }
    }
}
)

export const {increment, decrement, remove, removeOrder, addToOrder, changeOrder} = BusketSlice.actions

export default BusketSlice.reducer