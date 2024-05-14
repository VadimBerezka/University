import React from 'react';
import { Counter } from './features/counter/Counter';
import './App.css';
import Busket from './lab10/Busket.jsx'
import Order from './lab10/Order.jsx';
import ThankYoyForOrder from './lab10/TheEnd.jsx';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import SortTable from './lab10/SortTable.jsx'
import Catalog from "./lab10/Catalog"

function App() {
  return (
    <div className="App">
      <header className="App-header">
      <BrowserRouter>
      <Routes>
        <Route path="/" element={<Busket />} />
        <Route path="order" element={<Order/> } />
        <Route path="order/end" element={<ThankYoyForOrder/> } />
      </Routes>
    </BrowserRouter>
        {/* <Counter /> */}
        {/* <SortTable/>
        <Catalog/> */}
      </header>
    </div>
  );
}
  
export default App;
