import React from 'react';
import './App.css';
import SortTable from './lab10/SortTable.jsx'
import Catalog from "./lab10/Catalog"
import Busket from './lab10/Busket.jsx'
import Order from './lab10/Order.jsx';
import ThankYoyForOrder from './lab10/TheEnd.jsx';
import { BrowserRouter, Routes, Route } from 'react-router-dom';


function App() {
  return (
    <div className="App">
      <header className="App-header">
        <SortTable />
        <br />
        <Catalog />
        <br />
        <BrowserRouter>
          <Routes>
            <Route path="/" element={<Busket />} />
            <Route path="order" element={<Order />} />
            <Route path="order/end" element={<ThankYoyForOrder />} />
          </Routes>
        </BrowserRouter>
      </header>
    </div>
  );
}

export default App;
