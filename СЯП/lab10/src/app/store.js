import { configureStore } from '@reduxjs/toolkit';
import counterReducer from '../features/counter/counterSlice';
import busketReduser from '../lab10/BusketSlice';
import orderReduser from '../lab10/OrderSlice';
export const store = configureStore({
  reducer: {
    counter: counterReducer,
    busket: busketReduser,
    order: orderReduser
  },
});
