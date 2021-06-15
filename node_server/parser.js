const serialPort = require('serialport');
console.log('Started');

const parsers = serialPort.parsers;
const parser = new parsers.Readline({
  delimiter: '\r\n',
});

const port = new serialPort('/dev/cu.usbserial-1410', {
  baudRate: 9600,
  dataBits: 8,
  parity: 'none',
  stopBits: 1,
  flowControl: false,
});

port.pipe(parser);

parser.on('data', (data) => {
  console.log(data);
});
